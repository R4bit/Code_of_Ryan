#include <iostream>
#include <string>
using namespace std ;

// 普通类 实现：
class Calculator
{
public:
    int getResult(string oper)
    {
        if(oper == "+" ){
            return m_Num1 + m_Num2 ;
        }else if(oper == "-" ){
            return m_Num1 - m_Num2 ;
        }else if(oper == "*" ){
            return m_Num1 * m_Num2 ;
        }else if(oper == "/" ){
            return m_Num1 / m_Num2 ;
        }
        // 1.要扩展新的需求：需修改源码
        // 2.开闭原则：对扩展进行开放，对修改进行关闭
        // 3.所以，下面用多态实现计算器
        return 0 ;
    }

    int m_Num1 , m_Num2 ;

};

// 多态 实现：
// 计算器抽象类
class AbstractCalculator
{
public:
    // 纯虚函数：virtual int getResult() = 0 ;
    // 有纯虚函数的类 ： [抽象类]
    virtual int getResult() // 将被子类的同名函数覆盖
    {
        return 0 ;
    }

    int m_Num1 ;
    int m_Num2 ;

};

// 加法计算器类
class addCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2 ;
    }
};
// 减法计算器类
class decCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2 ;
    }
};
// 乘法计算器类
class mulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2 ;
    }
};
// 除法计算器类
class divCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 / m_Num2 ;
    }
};

// 普通计算器类
void test01()
{
    Calculator c ;
    c.m_Num1 = 10 ;
    c.m_Num2 = 20 ;

    cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl ;
    cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl ;
    cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl ;
    cout << c.m_Num1 << " / " << c.m_Num2 << " = " << c.getResult("/") << endl ;
}
// 多态计算器类 (父类指针或引用 指向子类对象)
void test02()
{
    // +
    AbstractCalculator * abc = new addCalculator ; //core

    abc->m_Num1 = 10 ;
    abc->m_Num2 = 10 ;

    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl ;

    delete abc ;
    abc = NULL ;

    // - 
    abc = new decCalculator ;

    abc->m_Num1 = 10 ;
    abc->m_Num2 = 10 ;

    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl ;

    delete abc ;
    abc = NULL ;

}
int main()
{
    cout << "normal way : " << endl ;
    test01() ;
    cout << endl ;
    cout << "polymorphism way : " << endl ;
    test02() ;

    return 0 ;
}
