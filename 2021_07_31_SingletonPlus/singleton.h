
// ����ģʽ

// 1������ģʽ
// ʵ�ַ�ʽ��ֱ�Ӷ��徲̬����
// �ŵ㣺û�ж��߳�����==>��Ϊmain����ִ��ǰ��
// ȫ����������ྲ̬��Ա�����Ѿ�����ʼ��
// ȱ�㣺���ܻᵼ�³�����������
       // �������������ϵ�Ķ��ʵ�������޷������������������ĳ�ʼ����������˳��
       // ���ܻᵼ�³������
// Ӧ�ó�����
// ���������������ڸ߲���������Ƶ��ʹ�ã�����Ҫ��ϸߣ�
// ʹ�ö���������������Դ������������Ӧ�ٶȸ���
class Singleton1{
public:
	static Singleton1& GetInstance()
	{
		return _sl;
	}
private:
	Singleton1()
	{}
	Singleton1(const Singleton1& ) = delete;
	Singleton1& operator=(const Singleton1&) = delete;
	static Singleton1 _sl;
};
Singleton1 Singleton1::_sl;


