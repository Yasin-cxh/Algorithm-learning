/*
* 什么是单例模式？任何情况下只有一个实例的类就是单例类
* 应用场景：一些工具类只需要一个实例就可以。
* 如果频繁new会产生额外的开销，如果使用全局变量则会影响封装，这个时候就需要单例类
*
* 单例模式需要注意什么？
* 1.多线程情况下也能正常运行
* 2.多线程情况下不能频繁造成线程阻塞影响效率
*
* 通过单例模式，可以做到：
* 1.确保一个类只有一个实例被创建
* 2.提供了一个对对象的全局访问指针
*
* 单例模式分类
* 1.空间换时间——饿汉式(奇奇怪怪的的名词又增加了)
* 一开始就初始化了单例类，使用时直接调用，对时间要求大的情况使用
* 2.时间换空间——懒汉式
* 使用时才初始化实例，对空间敏感的情况使用
*/

#include <cstdio>
#include <cstring>

//懒汉式
class CSingleton_lazy_not_thread_safe
{
public:
    static CSingleton_lazy_not_thread_safe* GetInstance();//静态成员函数

private:
    CSingleton_lazy_not_thread_safe(){};//私有默认构造函数
    static CSingleton_lazy_not_thread_safe *_instance;//静态成员变量需要初始化
};

CSingleton_lazy_not_thread_safe* CSingleton_lazy_not_thread_safe::GetInstance()
{   
    if(_instance == nullptr){//此处不是线程安全的，可能多个线程同时运行到这，产生多个实例
        _instance = new CSingleton_lazy_not_thread_safe();//懒汉式的关键是使用时再初始化
    }
    return _instance;
}

CSingleton_lazy_not_thread_safe* CSingleton_lazy_not_thread_safe::_instance = nullptr;


class CSingleton_lazy_thread_safe
{
private:
    CSingleton_lazy_thread_safe();
public:
    static CSingleton_lazy_thread_safe* GetInstance();
private:
    static CSingleton_lazy_thread_safe* _instance;   
};

CSingleton_lazy_thread_safe* CSingleton_lazy_thread_safe::_instance = nullptr;

CSingleton_lazy_thread_safe* CSingleton_lazy_thread_safe::GetInstance()
{
    if(_instance == nullptr){//避免重复lock阻塞线程
        lock();
        if(_instance == nullptr){
            _instance = new CSingleton_lazy_thread_safe();
        }
        unlock();
    }
    return _instance;
}

//饿汉式
class CSingleton_hungry
{
public:
    static CSingleton_hungry *GetInstance();//静态成员函数的定义可以在类内也可以在类外，统一在类外

private:
    CSingleton_hungry();
    static CSingleton_hungry* _instance;
   
};

CSingleton_hungry* CSingleton_hungry::_instance = new CSingleton_hungry();//初始化就是实例

CSingleton_hungry::CSingleton_hungry()
{
    printf("enter CSingleton_hungry_thread_safe()\n");
}

CSingleton_hungry* CSingleton_hungry::GetInstance()
{
    return _instance;
}

