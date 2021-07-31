
// 单例模式

// 1、饿汉模式
// 实现方式：直接定义静态对象
// 优点：没有多线程问题==>因为main函数执行前，
// 全局作用域的类静态成员变量已经被初始化
// 缺点：可能会导致程序启动缓慢
       // 如果存在依赖关系的多个实例对象，无法决定这这个单例对象的初始化和析构的顺序
       // 可能会导致程序崩溃
// 应用场景：
// 如果这个单例对象在高并发环境下频繁使用，性能要求较高，
// 使用饿汉面试来避免资源竞争，提升响应速度更好
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


