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

void initialize(int name)
{
    node L ;
    L -> val = name ;
    L -> exp = NULL ;
    L -> next = NULL ;
}//initialize
void insertFirst(node &L , int val, int exp) 
{
   //create a link
   node *new = (struct node*) malloc(sizeof(struct node));
   
   new->val = val ;
   new->exp = exp ;
   new->next = L->next ;
   L->next = new ;
      
}
void traverse(/////////struct node *L)
{
   // reset to head
   struct node *ptr = head;
   //printf("\nhead address: %p\n", head);
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) 
   {
      printf("(%d*X^%d ,%p) ",ptr->val,ptr->exp,ptr->next);
      //printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	//end at the last node

   printf(" ]");
}
int main()
{
   insertFirst(5,5);
   insertFirst(4,4);
   insertFirst(3,3);
   insertFirst(2,2);
   insertFirst(1,1);

   traverse
   

}
/*

void insertFirst(int val, int exp) 
{
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->val = val;
   link->exp = exp;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
   //printf("current head address: \n%p\n", head);
}
*/