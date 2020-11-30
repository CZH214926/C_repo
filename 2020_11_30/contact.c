#include"contact.h"

void Menu()
{
	printf("###################################\n");
	printf("##1.Add  2.Del   3.Search 4.Mod####\n");
	printf("##5.Show 6.Clear 7.Sort   0.Exit###\n");
}
//��ʼ���ṹ��
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
		//����ͨѶ¼
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
		//�Ȱ�ͨѶ¼ͷ��������֪��cap��size,�Ϳ�������ռ��ˣ�
		//������ռ��ٰ����������е��˶���������Ķѿռ���
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
		//�������
		person_t* p = &((*ct)->persons[(*ct)->size]);
		//�������Ա����䣬�绰��סַ
		printf("������");
		scanf(" %s", p->name);
		printf("�Ա�");
		scanf(" %c", &(p->sex));
		printf("���䣺");
		scanf(" %d", &(p->age));
		printf("�绰:");
		scanf(" %s", p->tel);
		printf("סַ��");
		scanf(" %s", p->addr);
		
		(*ct)->size += 1;
		
	}
	else{
		//�ռ����ˣ�������ʧ����
		printf("inc error!\n");
	}

}

void ShowContact(contact_t* ct){
	assert(ct);
	printf("| %10s|%10s\n |\n", "����", "�绰");
	for (int i = 0; i < ct->size; i++){
		printf("| %10s | %10s\n |\n", ct->persons[i].name, ct->persons[i].tel);
	}
}
static int IsEmpty(contact_t* ct){
	return ct->size == 0;//1Ϊ�գ�0Ϊ�ǿ�
}

void DelPerson(contact_t* ct){
	assert(ct);
	if (!IsEmpty(ct)){
		printf("��������Ҫɾ���˵ĵ绰:");
		char tel[SIZE / 6] = {0};
		scanf(" %s", tel);
		int pos = FindPerson(ct, tel);
		if (pos >= 0){
			ct->persons[pos] = ct->persons[ct->size - 1];
			ct->size -= 1;
		}
		else{
			printf("��Ҫɾ�����˲����ڣ�\n");
		}

	}
	else{
		printf("ͨѶ¼Ϊ�գ�\n");
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
	//����ͨѶ¼�ṹ����������������ֱ�д�뵽Ӳ����
	fwrite(ct, sizeof(contact_t), 1, fp);
	fwrite(ct->persons, sizeof(person_t), ct->size, fp);
	fclose(fp);
}