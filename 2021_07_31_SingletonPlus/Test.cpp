#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

// 单例模式---懒汉模式
// 实现方式：静态指针 + C++11的unique_lock + 用时初始化 + 内嵌垃圾回收类（也可以不写）
// 应用场景：如果单例对象构造十分耗时或者占用较多资源，比如加载插件、初始化网络连接
//          读取文件等，有可能该单例对象并不是程序运行的时候就会用到，如果一开始就
//          就进行单例对象的初始化，就会导致程序启动的时候非常缓慢，所以懒汉模式(延迟加载)
//          就比较适合这种情况
class Singleton{
public:
	static Singleton* GetInstance()
	{
		if (_psl == nullptr)
		{
			// 双检查保证效率和线程安全
			unique_lock<mutex> lock(_mtx);
			// 不加锁对象唯一性被破坏，同时还有内存泄露
			if (_psl == nullptr)
			{
				cout << "单例对象被创建" << endl;
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
				cout << "单例对象被析构" << endl;
			}
			
		}
	};
	// 定义静态成员变量，用于析构释放单例对象资源
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