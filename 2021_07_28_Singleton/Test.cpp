#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

// ����ģʽ---����ģʽ
// ʵ�ַ�ʽ����ָ̬�� + C++11��unique_lock + ��ʱ��ʼ�� + ��Ƕ����������
class Singleton{
public:
	static Singleton* GetInstance()
	{
		if (_psl == nullptr)
		{
			// ˫��鱣֤Ч�ʺ��̰߳�ȫ
			unique_lock<mutex> lock(_mtx);
			// ����������Ψһ�Ա��ƻ���ͬʱ�����ڴ�й¶
			if (_psl == nullptr)
			{
				cout << "�������󱻴���" << endl;
				_psl = new Singleton;
			}
		}
		return _psl;
	}
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (Singleton::_psl)
			{
				delete Singleton::_psl;
				cout << "������������" << endl;
			}
			
		}
	};
	// ���徲̬��Ա���������������ͷŵ���������Դ
	static CGarbo Garbo;
private:
	Singleton()
	{}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton* _psl;
	static mutex _mtx;
};
Singleton* Singleton::_psl = nullptr;
mutex Singleton::_mtx;
Singleton::CGarbo Garbo;
void func()
{
	cout << Singleton::GetInstance() << endl;
}

int main()
{

	thread t1(func);
	thread t2(func);
	t1.join();
	t2.join();

	return 0;
}