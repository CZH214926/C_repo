#include"contact.h"

void Menu()
{
	printf("###################################\n");
	printf("##1.Add  2.Del   3.Search 4.Mod####\n");
	printf("##5.Show 6.Clear 7.Sort   0.Exit###\n");
}
//初始化结构体
contact_t* InitContact(){
	contact_t *ct = NULL;
	FILE* fp = fopen(SAVE_FILE, "rb");
	if (NULL == fp)
	{
		printf("use default:init Contact ing...\n");
		int size = sizeof(contact_t)+sizeof(person_t)*NUM;
		ct = (contact_t*)malloc(size);
		if (NULL == ct){
			printf("Contact malloc error!\n");
			exit(1);
		}
		ct->cap = NUM;
		ct->size = 0;
		printf("use default:init Contact done!\n");
	}
	else{
		//读入通讯录
		printf("read in contact from disk ing....\n");
		contact_t temp;
		fread(&temp, sizeof(contact_t), 1, fp);
		int size = sizeof(contact_t)+sizeof(person_t)*temp.cap;
		 ct = (contact_t*)malloc(size);
		if (NULL == ct){
			printf("Contact malloc error!\n");
			exit(1);
		}
		ct->cap = temp.cap;
		ct->size = temp.size;
		//先把通讯录头读进来，知道cap和size,就可以申请空间了，
		//申请完空间再把柔性数组中的人读到我申请的堆空间里
		fread(ct->persons, sizeof(person_t), temp.size, fp);
		fclose(fp);
		printf("read in contact from disk done....\n");
	}

	return ct;
}
static int FindPerson(contact_t* ct, const char* tel){
	assert(ct&&tel);
	int i;
	for (i = 0; i < ct->size; i++){
		if (strcmp(ct->persons[i].tel, tel) == 0){
			return i;
		}
	}
	return -1;
}
static int IsFull(contact_t* ct){
	return ct->cap == ct->size;
}
static int Inc(contact_t ** ct){
	printf("contact is full,incing....\n");

	*ct = (contact_t *)realloc(*ct, sizeof(**ct) + INC_SIZE*sizeof(person_t));

	if (NULL == *ct){
		return 0;
	}

	((*ct)->cap) += INC_SIZE;
	printf("contact is full,inc done....\n");
	return 1;
}
void AddPerson(contact_t** ct){
	if (!IsFull(*ct) || Inc(ct)){
		//正常添加
		person_t* p = &((*ct)->persons[(*ct)->size]);
		//姓名，性别，年龄，电话，住址
		printf("姓名：");
		scanf(" %s", p->name);
		printf("性别：");
		scanf(" %c", &(p->sex));
		printf("年龄：");
		scanf(" %d", &(p->age));
		printf("电话:");
		scanf(" %s", p->tel);
		printf("住址：");
		scanf(" %s", p->addr);
		
		(*ct)->size += 1;
		
	}
	else{
		//空间满了，申请又失败了
		printf("inc error!\n");
	}

}

void ShowContact(contact_t* ct){
	assert(ct);
	printf("| %10s|%10s\n |\n", "姓名", "电话");
	for (int i = 0; i < ct->size; i++){
		printf("| %10s | %10s\n |\n", ct->persons[i].name, ct->persons[i].tel);
	}
}
static int IsEmpty(contact_t* ct){
	return ct->size == 0;//1为空，0为非空
}

void DelPerson(contact_t* ct){
	assert(ct);
	if (!IsEmpty(ct)){
		printf("请输入你要删除人的电话:");
		char tel[SIZE / 6] = {0};
		scanf(" %s", tel);
		int pos = FindPerson(ct, tel);
		if (pos >= 0){
			ct->persons[pos] = ct->persons[ct->size - 1];
			ct->size -= 1;
		}
		else{
			printf("你要删除的人不存在！\n");
		}

	}
	else{
		printf("通讯录为空！\n");
	}
}

void Clear(contact_t* ct){
	ct->size = 0;
}

void SaveContact(contact_t* ct){
	assert(ct);
	FILE* fp = fopen(SAVE_FILE, "wb");
	if (NULL == fp){
		printf("file open error and save failure!\n");
	}
	//将用通讯录结构体和里面的柔性数组分别写入到硬盘中
	fwrite(ct, sizeof(contact_t), 1, fp);
	fwrite(ct->persons, sizeof(person_t), ct->size, fp);
	fclose(fp);
}