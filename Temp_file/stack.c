/*
Author: Qinbing Fu
This introduces stack operations in C programming.
*/

#include <stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1; 

int isempty()
{

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull()
{

   if(top == MAXSIZE - 1)
      return 1;
   else
      return 0;
}

int peek()
{
   return stack[top];
}

int pop()
{
   int data;
	
   if(!isempty())
   {
      data = stack[top];
      top = top - 1;
      printf("Poping data: %d\n", data);
      return data;
   } 
   else 
   {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

void push(int data)
{

   if(!isfull())
   {
      top = top + 1;
      stack[top] = data;
      printf("Pushing data: %d\n", data);
   } 
   else
   {
      printf("Could not insert data, Stack is full.\n");
      //homework:
      //increase size of stack
      //...
   }
}

int main() {
   // push items on to the stack 
   push(1);
   push(2);
   push(3);
   push(4);
   push(5);
   push(6);
   push(7);
   push(8);
   //push(9);
   //push(10);

   printf("Stack full: %s\n", isfull()?"true":"false");
   printf("Stack empty: %s\n", isempty()?"true":"false");

   printf("Element at top of the stack: %d\n" ,peek());

   // print stack data 
   while(!isempty()) {
      int data = pop();
      //printf("%d\n",data);
   }

   printf("Stack full: %s\n", isfull()?"true":"false");
   printf("Stack empty: %s\n", isempty()?"true":"false");
   
   return 0;
}

