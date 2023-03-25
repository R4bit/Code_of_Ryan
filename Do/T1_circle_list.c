/*
This shows the coding basics of circular-linked-list in C programming.
【实验题 1】在单链表和 &循环链表& 的现有demo程序基础上，
编写从链表中间位置删除和插入元素的算法。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
   int data;
   int key;
	
   struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;   //new -> compared to the first divertion.
struct node *current = NULL;

bool isEmpty() 
{
   return head == NULL;
}

int length() 
{
   int length = 0;

   //if list is empty
   if(head == NULL) 
   {
      return 0;
   }

   current = head->next;

   // here different to single linked list
   while(current != head) 
   {
      length++;
      current = current->next;   
   }
	
   return length;
}

//insert link at the first location
void insertFirst(int key, int data) 
{
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
   // attention here, difference
   if (isEmpty()) 
   {
      head = link;
      head->next = head;
      tail = head;
   } 
   else 
   {
      //point it to old first node
      link->next = head;
		
      //point first to new first node
      head = link;

      //update tail node
      tail->next = head;
   }  
   //printf("%p,%d,%d,%p\n",link,link->data,link->key,link->next);
   //printf("current head: %p\n",head);
   //printf("current tail->next: %p\n",tail->next);  
}

//delete first item
struct node *deleteFirst() 
{

   //save reference to first link
   struct node *tempLink = head;
	
   if(head->next == head) 
   {  
      head = NULL;
      return tempLink;
   }     

   //mark next to first link as first 
   head = head->next;

   //update tail node
   tail->next = head;
	
   //return the deleted link
   return tempLink;
}

//display the list
void printList() 
{

   struct node *ptr = head;
   printf("\n[ ");
	
   //start from the beginning
   if(head != NULL) 
   {
      // difference here
      while(ptr->next != head) 
      {
         //printf("(%d,%d) ",ptr->key,ptr->data);
         printf("(%p,%d,%d,%p) ",ptr,ptr->key,ptr->data,ptr->next);
         ptr = ptr->next;
      }

      //print the last node
      //printf("(%d,%d) ",ptr->key,ptr->data);
      printf("(%p,%d,%d,%p) ",ptr,ptr->key,ptr->data,ptr->next);
   }
	
   printf(" ]");
}

int main() 
{
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,40);
   insertFirst(5,50);
   insertFirst(6,60); 

   printf("Original List: "); 
	
   //print list
   printList();

   
   while(!isEmpty()) {            
      struct node *temp = deleteFirst();
      printf("\nDeleted value:");  
      printf("(%d,%d) ",temp->key,temp->data);
   }   
	
   printf("\nList after deleting all items: ");
   printList();
   
   return 0;
}
