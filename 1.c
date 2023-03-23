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

void initialize(node*header)
{
   
   //header = (node*) malloc(sizeof(node*));
   
   header->val = 0 ;
   
   header->exp = 0 ;
   
   header->next = NULL ;
   
}
void insertFirst(node *head, int val, int exp)
{
   if (head == NULL) 
   {
   // if header is NULL, initialize it.
      head = (node*) malloc(sizeof(node));
      head->val = 0;
      head->exp = 0;
      head->next = NULL;
   }
   // new node
   node *new = (node*) malloc(sizeof(node));
   new->val = val;
   new->exp = exp;
   new->next = head->next;

   head->next = new;
printf("new node :%d \n" , head->next->val);
printf("Founc \"insertFirst\" --over\n");
}
/*
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
*/
int main()
{
   //initialize three headers of three polynomials.
   node *A , *B , *C ;
   A = (node*)malloc(sizeof(node*));
   initialize(A);
printf("hello!\n");
   insertFirst(A,5,5);
printf("hello!\n");
   insertFirst(A,4,4);
printf("hello!\n");
   insertFirst(A,3,3);
printf("hello!\n");
   insertFirst(A,2,2);
   insertFirst(A,1,1);
printf("successed! \n");
printf("%d \n" , *A->next->next );
printf("successed! \n");//4
   free(A);
   //traverse(A);

}