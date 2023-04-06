#include <stdio.h>

void fun(int *a, int *b)
{
	int c = 0;
	c = *a;
    
    printf("%d \n" , c );
	*a = *b;
	*b = c;
}
int main()
{
    int a = 0 , b = 1 ;
    printf("%d , %d \n" , a , b );
    fun(&a , &b);
    printf("%d , %d \n" , a , b );

}