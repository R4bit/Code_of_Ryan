/*
Author: Qinbing Fu
Date: 2023 Mar
This introduces queue operations in C programming.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek()
{
   return intArray[front];
}

bool isEmpty()
{
   return itemCount == 0;
}

bool isFull()
{
   return itemCount == MAX;
}

int size()
{
   return itemCount;
}  

void insert(int data)
{

   if(!isFull())
   {
	
      if(rear == MAX-1)
      {
         rear = -1;
      }       

      intArray[++rear] = data;
      itemCount++;
   }
}

int removeData()
{
   int data = intArray[front++];
	
   if(front == MAX)
   {
      front = 0;
   }
	
   itemCount--;
   return data;
}

int main()
{
   /* insert 5 items */
   insert(1);
   insert(2);
   insert(3);
   insert(4);
   insert(5);
   
   printf("Element at front: %d\n",peek());

   // front : 0
   // rear  : 4
   // ------------------
   // index : 0 1 2 3 4 
   // ------------------
   // queue : 1 2 3 4 5
   insert(100);

   // front : 0
   // rear  : 5
   // ---------------------
   // index : 0 1 2 3 4  5 
   // ---------------------
   // queue : 3 5 9 1 12 100
	
   if(isFull())
   {
      printf("Queue is full!\n");
   }

   // remove one item 
   int num = removeData();
	
   printf("Element removed: %d\n",num);
   // front : 1
   // rear  : 5
   // -------------------
   // index : 1 2 3 4  5
   // -------------------
   // queue : 2 3 4 5  100

   // insert more items
   insert(200);

   // front : 1
   // rear  : -1
   // ----------------------
   // index : 0   1 2 3 4 5
   // ----------------------
   // queue : 200 2 3 4 5 100

   // As queue is full, elements will not be inserted.
   insert(1000);
   insert(2000);

   // ----------------------
   // index : 0   1 2 3 4 5
   // ----------------------
   // queue : 200 2 3 4 5 100
   printf("Element at front: %d\n",peek());

   printf("----------------------\n");
   printf("Queue:  ");
   while(!isEmpty())
   {
      int n = removeData();
      printf("%d ",n);
   }

   return 0;
}

