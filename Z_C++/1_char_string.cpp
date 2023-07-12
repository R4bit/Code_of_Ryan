#include <iostream>
#include <stdbool.h>

using namespace std ;

int main()
{
    //char

    char ch = 'a' ;
    char ch2 = 'A' ;

    cout << "a :" << ch << endl ;
    cout << "a's ASCLL code :" << (int )ch << endl ; // 97
    cout << "A :" << ch2 << endl ;
    cout << "A's ASCLL code :" << (int )ch2 << endl ; // 65

    cout << "\\HELLO\tHELLO\n" << endl ;  // '\t' accounts 8 spaces!

    //string

    //C style :
    char str[] = "hello world" ;
    cout << str << endl ;

    //C++ style :
    string str2 = "hello world" ;
    cout << str2 << endl ;

    bool b = true ;
    cout << b << endl ;
    b = 0 ;
    cout << b << endl ;

    return 0 ;
}