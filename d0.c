
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
   int val;
   int exp;
   struct node* next;
}node;

void insertFirst(node** head, int val, int exp)
{
   // new node*
   node* neww = (node*) malloc(sizeof(struct node));

   if(neww == NULL){
      printf("malloc wrong ! \n");
      return ;
   }

   neww->val = val;
   neww->exp = exp;
   neww->next = *head;
   *head = neww;
}

void traverse(node* head)
{
   // reset to the first node* instead of the "header".
   node* ptr = head ;

   // print as : [  (....)+(....)+(....)+(....)+ ... ]
   printf("\n[ ");
   
   while(ptr != NULL) 
   {

      if(ptr->val > 0 )
      printf("(%d*X^%d)" , ptr->val , ptr->exp );
      else if(ptr->val < 0 )
      printf("((%d)*X^%d)" , ptr->val , ptr->exp );
      // case coefficient == 0 :
      else 
      {}
      // Judge --> find the right place to add " + "
      if(ptr->next && ptr->val != 0 )  printf("+");

      // go on
      ptr = ptr->next;

   }
   // over
   printf(" ]");
}

int main()
{
   node* A , *B , *C , *result ;
   A = (node*)malloc(sizeof(node));
   B = (node*)malloc(sizeof(node));
   C = (node*)malloc(sizeof(node));
   result = (node*)malloc(sizeof(node));
   
   A = NULL;
   B = NULL;
   C = NULL;
   result = NULL;


   insertFirst(&A,5,5);
   insertFirst(&A,4,4);
   insertFirst(&A,3,3);
   insertFirst(&A,2,2);
   insertFirst(&A,1,1);
  
   traverse(A);
   printf("\ninit A over \n");

   insertFirst(&B,1,1);
   insertFirst(&B,2,2);
   insertFirst(&B,3,3);
   insertFirst(&B,0,4);
   insertFirst(&B,0,5);

   traverse(B);
   printf("\ninit B over \n");
   
   insertFirst(&B,-1,1);
   insertFirst(&B,-2,2);
   insertFirst(&B,-3,3);
   insertFirst(&B,9,4);
   insertFirst(&B,0,5);

   traverse(B);
   printf("\ninit B over \n");
   
   
  // add(A,B,result);
  // traverse(result);free(A);
free(B);
free(C);
free(result);

}