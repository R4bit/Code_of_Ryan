#include <iostream>

using namespace std ;

int max( int d , int c ) ;
// or : int max( int , int )
// or : int max( int a , int b )
// all three types above are right.

int main()
{

   cout << max( 1 , 2 ) << endl ;
    
   return 0 ; 
}

int max( int a , int b )
{
   return a > b ? a : b ;
}