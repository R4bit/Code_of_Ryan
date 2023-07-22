#include <iostream>

using namespace std ;

class Person
{
    // friend void founc01(int a , int b ); 全局函数友元，可以访问这个类的私有变量。
    // friend class goodGay; 类友元
    // friend void goodGay::visit(); 成员函数友元
public:
    // 构造函数
    Person(int age)
    {
        // age = age ; --> WRONG
        // m_aeg = age ; --> RIGHT
        this->age = age ; // RIGHT , 'this' points to the founction's Object
                            // 'this' can deal with the collision of name.
    }

    // 成员函数
    /*
    void PersonAddAge(Person &p) 
    {
        this->age += p.age ;
    }
    //// p2.PersonAddAge(p1).PersonAddAge(p1) --> error: invalid use of 'void'
    */

    Person& PersonAddAge(Person &p) // ：带引用：一直返回原对象
    // Person PersonAddAge(Person &p) : 返回一个新的对象
    {
        this->age += p.age ;
        return *this ;
    }

    // 成员变量
    int age ; // means:  member_Age

};
  
// void test01

int main()
{
    Person p1( 1 ) ;
    Person p2( 10 ) ; // 用默认构造函数传入年龄成员变量值

    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p2) ; // core
    // --> age : 24  =  (10+1+1)*2
    cout << "age of p2 is : " << p2.age << endl ;

    system("pause") ;
    system("cls") ;
}