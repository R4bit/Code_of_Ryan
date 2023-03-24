#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node1
{
   int val;
   int exp;
   struct node1 *next;
}node1 , *node;

void initialize(node header)
{
   
   //header = (node*) malloc(sizeof(node*));
   
   header->val = 0 ;
   
   header->exp = 0 ;
   
   header->next = NULL ;
   
}
void insertFirst(node head, int val, int exp)
{
   // new node
   node neww = (node) malloc(sizeof(struct node1));
   if(neww == NULL)
   {
      printf("wrong ! \n");
   }
   else
   {
   neww->val = val;
   neww->exp = exp;
   neww->next = head->next;
   head->next = neww;
   }
}

void traverse(node L)
{
   // reset to the first node instead of the "header".
   node ptr = L->next ;

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

void add(node A , node B , node result) // need to add at tail when constructing "result".
{
   //init head of "result" :
   result = malloc(sizeof(struct node1));
   result->val = result->exp = 0 ;
   result->next = NULL ;

   node p1 = A->next , p2 = B->next ;

   while(p1 || p2) // which means need to go on.
   {
    // init a node at first to provide space to operate :
    node new = malloc(sizeof(struct node1));
    new->val = new->exp = 0 ;
    new->next = NULL ;
    // introduce "tail" :   
    node tail = malloc(sizeof(struct node1));
    tail = result ;
    while(tail)
    tail = tail->next ;  //tail.

    // p1 longer :
    if(p1 && !p2)
    {
        new->val = p1->val ;
        new->exp = p1->exp ;
        new->next = NULL ;
    // put new to tail of "result" :
        tail->next = new ;
        tail = new ;
        p1 = p1->next ;
    }
    // p2 longer :
    else if(p2 && !p1)
    {
        new->val = p2->val ;
        new->exp = p2->exp ;
        new->next = NULL ;
    // put new to tail of "result" :
        tail->next = new ;
        tail = new ;
        p2 = p2->next ;
    }
    // normal case , excute add opreation :
    else
    {
    // assignment :
        new->val = p1->val + p2->val ;
        new->exp = p1->exp ;
        new->next = NULL ;
    // put new to tail of "result" :
        tail->next = new ;
        tail = new ;
    
        p1 = p1->next ;
        p2 = p2->next ;
        
    }
   }
}

int main()
{
   //initialize three headers of three polynomials.
   node A , B , C , result;
   A = (node)malloc(sizeof(struct node1));
   B = (node)malloc(sizeof(struct node1));
   C = (node)malloc(sizeof(struct node1));
   result = (node)malloc(sizeof(struct node1));
   initialize(A),initialize(B);
   initialize(C);

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
   
   
   insertFirst(B,-1,1);
   insertFirst(B,-2,2);
   insertFirst(B,-3,3);
   insertFirst(B,-0,4);
   insertFirst(B,-0,5);

   traverse(B);
   printf("\ninit B over \n");
   
   add(A,B,result);
   traverse(result);
   free(A) , free(B) , free(C) , free(result) ;

}