#include <iostream>

using namespace std ;

class Base
{
public:
    Base()
    {
        m_A = 100 ;
    }
    
    void founc()
    {
        cout << "Base(father class) --founc() runned" << endl ;
    }

    int m_A ;
};

// 多继承：clsaa Son : public Father01 , private Father02 , public Father03   
class Son : public Base // 以Public方式继承父类Base
{
public:
    Son()
    {
        m_A = 200 ;
    }

    void founc()
    {
        cout << "Son --founc() runned " << endl ;
    }

    int m_A ;
};

void test01() // 调用变量
{
    Son s ;
    // 父类，子类重名时，直接调用名称，会调用[子类的]值
    cout << "\nin class Son , m_A = " << s.m_A << endl ;
    cout << "in class Base(father class) , m_A = " << s.Base::m_A << endl ;
                                                    //  ^^^^^^ 加个父类作用域就可以访问父类里的重名的值了
}
void test02() // 调用函数
{
    Son s ;

    s.founc() ;
    s.Base::founc() ;
    // 子类没有重载，父类里有重载时：
    // 必须加上[父类作用域]才能调用父类的重载函数
}


int main()
{
    // s.m_A --> Son's m_A | s.Base::m_A --> Father's m_A
    test01() ;
    cout << endl ;
    // s.founc() --> Son's founc | s.Base::founc() --> Father's founc
    test02() ; 
    cout << endl ;

    return 0 ;
}