/*
Author: Qinbing Fu , Renyvan Liu.
Date: 2023 Apr
This introduces an implementation of tree creation and traversal in C programming.
1. in-order traversal
2. pre-order traversal
3. post-order traversal
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node 
{
   //node data stored
   int data; 
	
   //children pointers
   struct node *leftChild;
   struct node *rightChild;
}node ;

node *root = NULL ;

void insert(int data)
{
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty
   if(root == NULL)
   {
      root = tempNode;
   } 
   else
   {
      current = root;
      parent = NULL;

      while(1)
      {
         parent = current;
         
         //go to left of the tree
         if(data < parent->data)
         {
            current = current->leftChild;
            
            //insert to the left
            if(current == NULL)
            {
               parent->leftChild = tempNode;
               return;
            }
         }  //go to right of the tree
         else
         {
            current = current->rightChild;

            //insert to the right
            if(current == NULL)
            {
               parent->rightChild = tempNode;
               return;
            }
         }
      }
   }
}

// RECURTION version of founction "search" 
node* recursion_search(node* target_node , int num) // attempt to find num from node's son_node.
{
   if(target_node == NULL ){
      return NULL ;
   }

   struct node* temp = target_node ;

   if (temp->data == num ){
      return temp ; // Final return at here.
   }else if(temp->leftChild || temp->rightChild){

      if(temp->leftChild){
         recursion_search(temp->leftChild , num ) ;
      }else{
         recursion_search(temp->rightChild , num ) ;
      }
   }else{
      printf("not found...\n") ;
      return NULL ;
   }

}

void post_order_traversal(struct node* root)
{
   if(root != NULL)
   {
      post_order_traversal(root->leftChild);
      post_order_traversal(root->rightChild);
      printf("%d ", root->data);
   }
}

// Array tramsform to Tree : 

// put "i" into a tree_node :
node* to_node(int i )
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = i ;
    new_node->leftChild = NULL ;
    new_node->rightChild = NULL ; 
    return new_node ;
}

void attach(node** father, node* son)
{
    if (*father == NULL || son == NULL) {
        printf("\naaaaaaaaa\n");
        return ;
    }

    if ((*father)->leftChild == NULL) {
        (*father)->leftChild = son;
    } else if ((*father)->rightChild == NULL) {
        (*father)->rightChild = son;
    } else {
        printf("bbbbbbbbb");
        return ;
    }
}

int parents_index(int i )
{
    return i/2 ;
}

void Array_to_Tree(int* arr , int arr_num , node** tree_root )
{
    for(int i = 1 ; i < arr_num ; i ++ ) {
        node* son_node = to_node(arr[i]);

        if(i == 1 ) {
            *tree_root = son_node ;
        } else {
            node* temp = recursion_search(*tree_root , arr[parents_index(i)] );
            attach(&temp , son_node);
        }
    }
}

node* Array_to_Full_Binary_Tree(int* arr, int start, int end)
{
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    node* root = (node* )malloc(sizeof(node) ) ;
    root = to_node(arr[mid]);
    root->leftChild = Array_to_Full_Binary_Tree(arr, start, mid - 1);
    root->rightChild = Array_to_Full_Binary_Tree(arr, mid + 1, end);

    return root;
}

int main()
{
   
   int i;
   int array[SIZE] = { 10, 11, 20, 22, 30, 33, 40, 44, 50, 55 };

   for(i = 0; i < SIZE; i++)
      insert(array[i]);

   node* tempnode = recursion_search(root , 555) ;
   printf("\nsearch : %d \n" , tempnode->data );

    // Transform an Array to a Full_Tree :

    int index_to_parents_node_array[13] = {0,3,9,5,14,10,6,8,17,15,13,23,12 } ;
    //printf("\n\n%d" , index_to_parents_node_array[12] ) ;

    int* ptr = &index_to_parents_node_array[0] ; // put to a pointer. 
    //printf("\n%d\n" , ptr[12] ) ;

    node *Array_Transformed_Tree = (node* )malloc(sizeof(node* ) );

    Array_to_Tree( index_to_parents_node_array , 13 , &Array_Transformed_Tree ) ;

    printf("\n\n");
    post_order_traversal(Array_Transformed_Tree ) ;
 
/*
   // Founction "find" :
   node* finded = recursion_search(root , 40 );
   printf("\n\ndata : \n%d\nposition : \n%d\n\n " , finded->data , &finded ) ;
   
   // Founction "delete" :
   node* deleted_Node = (node*)malloc(sizeof(node* ) ) ;

   deleted_Node = deleteNode(33) ;

   pre_order_traversal(root ) ;
*/

   return 0;
}

