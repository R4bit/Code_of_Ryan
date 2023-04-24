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

struct node *root = NULL ;

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

// insert a node with data as argument, at any leaf nodes
struct node* insectAtLeaf(int data)
{}

// RECURTION version of founction "search" !
struct node* recursion_search(node* target_node , int num) // attempt to find num from node's son_node.
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
   }

}

// return target_node's parents , and their relationship such as "leftChild"
struct node* FindParent(node* target_node , int num) // attempt to find num from node's son_node.
{
   if(target_node == NULL ){
      return NULL ;
   }

   struct node* parent = target_node ; // this node is used for saving position of parent , which is convenient to RETURN.

   if(parent->leftChild->data == num || parent->rightChild->data == num){
      return parent ;
   }else if(parent->leftChild || parent->rightChild){

      if(parent->leftChild){
         recursion_search(parent->leftChild , num ) ;
      }else{
         recursion_search(parent->rightChild , num ) ;
      }
   }

}

// delete a node with data as argument
struct node* deleteNode(int num)
{
   node* parent = FindParent(root , num) ; // have found the parent node that need to be operated, and allocate it to node named "parent"
   node* deleted_node = (node* )malloc(sizeof(node*) ) ; // to store position of deleted_son_node.

   if(parent->leftChild){
      if(parent->leftChild->data == num){
         deleted_node = parent->leftChild ;
         parent->leftChild = NULL ;
      }
   }else{
      deleted_node = parent->rightChild ;
      parent->rightChild = NULL ;
   } 

   return deleted_node ;
}

// find the size of a tree
int size()
{}

// return the size of a tree
int height()
{}

struct node* search(int data)
{
   struct node *current = root;
   printf("Visiting elements: ");

   while(current->data != data)
   {
      if(current != NULL)
         printf("%d ",current->data);

      //go to left tree
      if(current->data > data)
      {
         current = current->leftChild;
      }
      //else go to right tree
      else
      {                
         current = current->rightChild;
      }

      //not found
      if(current == NULL)
      {
         return NULL;
      }
   }
   
   return current;
}

void pre_order_traversal(struct node* root)
{
   if(root != NULL)
   {
      printf("%d ",root->data);
      pre_order_traversal(root->leftChild);
      pre_order_traversal(root->rightChild);
   }
}

void inorder_traversal(struct node* root)
{
   if(root != NULL)
   {
      inorder_traversal(root->leftChild);
      printf("%d ",root->data);
      inorder_traversal(root->rightChild);
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

   printf("%d root\n", root->data);

   i = 11;
   struct node * temp = search(i);

   if(temp != NULL)
   {
      printf("[%d] Element found....", temp->data);
      printf("\n");
   }
   else
   {
      printf("[ x ] Element not found (%d)....\n", i);
   }
 
   i = 66;
   temp = search(i);

   if(temp != NULL)
   {
      printf("[%d] Element found....", temp->data);
      printf("\n");
   }
   else
   {
      printf("[ x ] Element not found (%d)....\n", i);
   }

   printf("\nPreorder traversal: ");
   pre_order_traversal(root);

   printf("\nInorder traversal: ");
   inorder_traversal(root);

   printf("\nPost order traversal: ");
   post_order_traversal(root);


    // Transform an Array to a Full_Tree :

    int index_to_parents_node_array[13] = {0,3,9,5,14,10,6,8,17,15,13,23,12 } ;
    //printf("\n\n%d" , index_to_parents_node_array[12] ) ;

    int* ptr = &index_to_parents_node_array[0] ; // put to a pointer. 
    //printf("\n%d\n" , ptr[12] ) ;

    node *Array_Transformed_Tree = (node* )malloc(sizeof(node* ) );

    Array_to_Tree( index_to_parents_node_array , 13 , &Array_Transformed_Tree ) ;
    printf("\n\n");
    pre_order_traversal(Array_Transformed_Tree ) ;
    printf("\n\n");
    post_order_traversal(Array_Transformed_Tree ) ;
    printf("\n\n");
    inorder_traversal(Array_Transformed_Tree ) ;
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

