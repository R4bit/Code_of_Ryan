/*
Author: Qinbing Fu
Date: 2023 June
Description: Quick Sort in C
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 21

// unsorted array
int intArray[MAX] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0, 2, 5, 8, 3, 6, 9, 1, 4, 7, 666 };

// function prototype
void printline(int);
void display(void);
void swap(int, int);
int partition(int, int, int);
void quickSort(int, int);
int main(void);


void printline(int count)
{
   int i;
	
   for(i = 0;i < count-1;i++)
   {
      printf("=");
   }
	
   printf("=\n");
}

void display(void)
{
   int i;
   printf("[");
	
   // navigate through all items
   for(i = 0;i < MAX;i++)
   {
      printf("%d ",intArray[i]);
   }
	
   printf("]\n");
}

void swap(int num1, int num2)
{
   int temp = intArray[num1];
   intArray[num1] = intArray[num2];
   intArray[num2] = temp;
}

int partition(int left, int right, int pivot)
{
   int leftPointer = left - 1;
   int rightPointer = right;

   while(true)
   {
      while(intArray[++leftPointer] < pivot)
      {
         // do nothing
         // meditation...
      }
		
      while(rightPointer > 0 && intArray[--rightPointer] > pivot)
      {
         // do nothing
         // meditation...
      }

      if(leftPointer >= rightPointer)
      {
         break;
      }
      else
      {
         printf(" item swapped :%d,%d\n", intArray[leftPointer], intArray[rightPointer]);
         swap(leftPointer,rightPointer);
      }
   }
	
   printf(" pivot swapped :%d,%d\n", intArray[leftPointer], intArray[right]);
   swap(leftPointer,right);
   printf("Updated Array: ");
   display();
   return leftPointer;
}

void quickSort(int left, int right)
{
   if(right-left <= 0)
   {
      return;   
   }
   else
   {
      int pivot = intArray[right];
      int partitionPoint = partition(left, right, pivot);
      // recursive algorithm
      quickSort(left,partitionPoint-1);
      quickSort(partitionPoint+1,right);
   }
}

int main(void)
{
   printf("Input Array: ");
   display();
   printline(50);
   quickSort(0,MAX-1);
   printf("Output Array: ");
   display();
   printline(50);

   return 0;
}

