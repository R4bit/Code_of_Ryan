#include <iostream>

using namespace std ;

// 函数声明时有默认值，函数实现时不能有默认参数
// int founc01(int a , int b = 1 , int c = 2 ) ;

int founc01( int a , int b = 1 , int c = 2 )
{
    return a + b + c ;
}

void founc02( int a , int ) // int 是[占位参数]
{
    cout << " this is founc " << endl ;
}

int main()
{  
    founc02( 1000 , 1000 ) ;

    // 某位置有默认值，则右边所有值都要有默认值
    cout << founc01(1000) << endl ;
    cout << founc01(1000 , 1000 ) << endl ; 
    cout << founc01(1000 , 1000 , 1000 ) << endl ;

    return 0 ;
}