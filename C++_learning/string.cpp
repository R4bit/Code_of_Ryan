#include<iostream>

using namespace std ;

int main()
{
    string a = "hello " ;
    string b = "world!" ;
    string c = a + b ;
    

    
//    cin >> c ;
/*
input : hello  world!
output : hello
*/
// need "getline()" to enter "  " element.

    getline(cin , c) ;
    string s_subed = c.substr(5) ;  // s_subed begin at the sixth leter !
    string s_subed2 = c.substr(2 , 5) ; // subed2 begin at the 3th leter ! , totally 5 leter !
/*
hello  wor   ld
hello  wor   ld
*/
    cout << c << c.length() << endl ;
    cout << s_subed << endl ;
    cout << s_subed2 << endl ;


    return 0 ;
}