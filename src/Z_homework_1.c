#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
   int val;
   int exp;
   struct node *next;
}node;

/* atempting in vain.... :
void initialize()
{
   printf("Enter name of ur polynomial : \n");
   int name ;
   scanf("%c" , &name);
   (node *)name = (node*) malloc(sizeof(node*));
   name->val = name ; //header "node" : assign "name" to val.
   name->exp = 0 ;
   name->next = NULL ;
}
void initialize(char *name) //a space exclusively to load the name.
{
   node **head = (node**) malloc(sizeof(node*));
   head = strdup(name);
   head->val = name ; //header "node" : assign "name" to val.
   head->exp = 0 ;
   head->next = NULL ;
}
*/
void initialize(node*header)
{
   
   header = (node*) malloc(sizeof(node*));
   
   header->val = 0 ;
   
   header->exp = 0 ;
   
   header->next = NULL ;
   
}
void insertFirst(node *name , int val, int exp)
{
   //create a link
   node *new = (node*) malloc(sizeof(node*));
   
   new->val = val ;
   new->exp = exp ;
   new->next = name->next ;
   name->next = new ;
   printf("%d \n" , new->val);
}

void traverse(node *L)
{

printf("successed!entered into Func traverse \n");	
   // reset to head
   node *ptr = L ;
   //printf("\nhead address: %p\n", head);
   printf("\n[ ");
printf("successed!entered into Func traverse \n");	
   //start from the beginning
   while(ptr != NULL) 
   {
      printf("(%d*X^%d ,%p) ",ptr->val,ptr->exp,ptr->next);
      //printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
printf("traverse: a spot over\n");
   }
	//end at the last node

   printf(" ]");
}

int main()
{
printf("successed!1 \n");//1
   //initialize three headers of three polynomials.
   node *A , *B , *C ;
   
printf("successed!2 \n");//2
   initialize(A);

printf("successed!3 \n");//3
   insertFirst(A,5,5);
   insertFirst(A,4,4);
   insertFirst(A,3,3);
   insertFirst(A,2,2);
   insertFirst(A,1,1);
printf("successed!4 \n");
printf("%d \n" , *A->next->next );
printf("successed!5...over \n");//4
   
   traverse(A);

}