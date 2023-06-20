#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    // these two have the same size of space : 8 bit
    int* space = (int* )calloc(2 , sizeof(int ) ) ;
    int* constantSpace = (int* )malloc( 2*sizeof(int) ) ;

    *space = 1 ;
    *(space + 1 ) = 5 ;
    
    printf("%d\n" , *space ) ;
    printf("%d\n" , *(space+1 ) ) ;
    printf("%d\n" , space ) ;
    


    return 0 ;
}