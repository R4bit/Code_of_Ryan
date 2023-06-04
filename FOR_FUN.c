/*
Author: Qinbing Fu
Date: 2023 Mar
This introduces expression parsing using stack.
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int e = 1 ;

void opreation()
{
   printf("\nOperation e value ....") ;
   e = 2 ;
}

int main()
{
   printf("e : %d" , e ) ;

   opreation() ;
   
   printf("\ne : %d" , e ) ;

}