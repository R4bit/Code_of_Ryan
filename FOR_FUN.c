#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* fun()
{
    int num = 1478420 ;
    return &num ;////WRONG
// warning: function returns 
// address of local variable [-Wreturn-local-addr] 
}

int main()
{
    int* ptr = NULL ;
    ptr = fun() ;

    
    printf("%d" , *ptr ) ;


    return 0 ;
}