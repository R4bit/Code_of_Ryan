/*
Author: Qinbing Fu
Date: 2023 June
Description: Merge Sort in C
*/

#include <stdio.h>
#include <time.h>
 
#define max 20

// unsorted array
int a[21] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0, 2, 5, 8, 3, 6, 9, 1, 4, 7, 666 };
// extra memory space for merging
int b[max];

// function prototype
void merging(int, int, int);
void mergeSort(int, int);
void main(void);


// merge two arrays
void merging(int low, int mid, int high)
{
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
   {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   // move elements (if existing) left in sub-array
   while(l1 <= mid)
      b[i++] = a[l1++];
   
   // move elements (if existing) left in sub-array
   while(l2 <= high)
      b[i++] = a[l2++];

   // copy elements back to the target array(unsorted a)
   for(i = low; i <= high; i++)
      a[i] = b[i];
}

// recursive merge sort
void mergeSort(int low, int high)
{
   int mid;
   
   if(low < high)
   {
      // find the middle point
      mid = (low + high) / 2;
      // recursive algorithm
      mergeSort(low, mid);
      mergeSort(mid+1, high);
      merging(low, mid, high);
   }
   else
      return;
}

void main(void)
{ 
   int i;
   // attention: timer
   clock_t start, end;
   double processTime;

   printf("List before merge sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);

   // sorting with timer
   start = clock();
   mergeSort(0, max);
   end = clock();
   processTime = (double)(end - start) / CLOCKS_PER_SEC;

   printf("\nList after merge sorting\n");

   printf("Merge sort process time: %.10f seconds\n", processTime);
   // increase the unsorted array to see run time
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);
}

