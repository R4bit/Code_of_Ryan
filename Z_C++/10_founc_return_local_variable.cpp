#include <iostream>

using namespace std ;

int* founc()
{
    int a = 10086 ;

    return &a ; // 不能返回局部变量的地址 ！！！！！！！！！！！！！
}

int main()
{
    int* a = founc() ;
    cout << *a << endl ;
    cout << *a << endl ;


    system("pause") ;
    system("cls") ;
    return 0 ;
}