// 引用 ：C++里 是指针常量 ， 指针指向的位置不可以改变。 //

#include <iostream>

using namespace std ;

//------------1.函数传递引用：（可以改变原值）-------------//
void refer_swap(int &a , int &b )
{
    int temp = a ;
    a = b ; 
    b = temp ;
}

//----------------2.函数返回引用：（需返回全局）---------------//
// 返回全局变量引用 ：
int& test01()
{
    int a = 20 ;
    return a ;
}
// 返回静态变量（全局）引用 ：
int& test02()
{
    static int a = 20 ;
    return a ;
}


int main()
{
    // 不能返回局部变量的引用：
  //  int& ref = test01() ;
  //  cout << "value : " << ref << endl ;
  //  cout << "value : " << ref << endl ;
    
    // 如果函数做左值，那么必须返回引用：
    int& ref2 = test02() ;
    cout << "value2 : " << ref2 << endl ;
    cout << "value2 : " << ref2 << endl ;

    test02() = 1000 ; // 函数做左值

    cout << "value2 : " << ref2 << endl ;
    cout << "value2 : " << ref2 << endl ;


    int a = 1 ;
    int b = 2 ;
    cout << "before swap : " << a << "\t" << b << endl ;

    cout << "pass value through \"REFER\" : " << endl ;
    refer_swap( a , b ) ;

    cout << "after swap : " << a << "\t" << b << endl ;

    return 0 ;
}