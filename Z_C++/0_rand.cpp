#include <iostream>

using namespace std ;

int main()
{
    int num = 0 ;
    for( int i = 1 ; i < 10 ; i ++ )
    {
        num = rand()%100 + 1 ; // random : 1 ~ 100
        cout << num << endl ;
    }

    return 0 ;
}