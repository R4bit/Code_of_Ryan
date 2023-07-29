#include <iostream>
using namespace std ;

// 抽象类：
class AbstractDrinking
{
public:
    virtual void Boil() = 0 ;
    virtual void Brew() = 0 ;
    virtual void PourInCup() = 0 ;
    virtual void PutSomething() = 0 ; // 将会被子类的同名函数覆盖

    virtual ~AbstractDrinking() = 0 ; // 纯虚析构的函数声明！

    void makeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
    /*
    // 虚析构 ： 析构父类，也能析构子类。
    // 否则 ： 父类析构，子类析构函数不运行，子类的堆区内存泄漏！！！
    virtual ~AbstractDrinking()
    {
       cout << "Father vanish........." << endl ;
    }
    */
};

// 纯虚析构：需要有声明(line 13)，也需要有实现(下一行)
AbstractDrinking::~AbstractDrinking() 
{
    cout << "Father PURE vanish.........." << endl ;
} 

// 制作咖啡：
class Coffee : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "Boil caffee" << endl ;
    }
    virtual void Brew()
    {
        cout << "Brew caffee" << endl ;
    }
    virtual void PourInCup()
    {
        cout << "Pour coffee" << endl ;
    }
    virtual void PutSomething()
    {
        cout << "Add some milk" << endl ;
    }

    ~Coffee()
    {
        cout << "Son01 vanish......" << endl ;
    }
};
// 制作红茶：
class Tea : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "Boil tea leaves" << endl ;
    }
    virtual void Brew()
    {
        cout << "Brew tea leaves" << endl ;
    }
    virtual void PourInCup()
    {
        cout << "Pour tea" << endl ;
    }
    virtual void PutSomething()
    {
        cout << "Add some wolfberry" << endl ;
    }

    ~Tea()
    {
        cout << "Son02 vanish......" << endl ;
    }
};

void doWork(AbstractDrinking* drink)
{
    drink->makeDrink() ;
    delete drink ;
    cout << endl ;
}
void test01()
{
    // coffee , using method 1 :
    AbstractDrinking* tea01 = new Coffee ;
    doWork(tea01) ;

    // tea , using method 2 :
    AbstractDrinking* tea02 = new Tea ;
    tea02->makeDrink() ;
    // or : tea02->AbstractDrinking::makeDrink() ;
    delete tea02 ;
}

int main()
{
    test01() ;

    return 0 ;
}