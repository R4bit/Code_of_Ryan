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
}

void traverse(node *L)
{
   // reset to the first node instead of the "header".
   node *ptr = L->next ;

   // print as : [  (....)+(....)+(....)+(....)+ ... ]
   printf("\n[ ");
   
   while(ptr) 
   {

      if(ptr->val > 0 )
      printf("(%d*X^%d)" , ptr->val , ptr->exp );
      else if(ptr->val < 0 )
      printf("((%d)*X^%d)" , ptr->val , ptr->exp );
      // case coefficient == 0 :
      else 
      {}
      // Judge --> find the right place to add " + "
      if(ptr ->next && ptr->val != 0 )  printf("+");
      // go on
      ptr = ptr->next;

   }
   // over
   printf(" ]");
}

int main()
{
   //initialize three headers of three polynomials.
   node *A , *B , *C ;
   A = (node*)malloc(sizeof(node*));
   B = (node*)malloc(sizeof(node*));
   C = (node*)malloc(sizeof(node*));
   initialize(A),initialize(B),initialize(C);
   
   insertFirst(A,5,5);
   insertFirst(A,4,4);
   insertFirst(A,3,3);
   insertFirst(A,2,2);
   insertFirst(A,1,1);
  
   traverse(A);
   printf("\ninit A over \n");

   insertFirst(B,1,1);
   insertFirst(B,2,2);
   insertFirst(B,3,3);
   insertFirst(B,0,4);
   insertFirst(B,0,5);

   traverse(B);
   printf("\ninit B over \n");
   
   insertFirst(C,-1,1);
   insertFirst(C,-2,2);
   insertFirst(C,-3,3);
   insertFirst(C,-4,4);
   insertFirst(C,-5,5);

   traverse(C);
   printf("\ninit C over \n");
   
}