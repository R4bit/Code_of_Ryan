/*
     ^ _ ^
    Wellcome to My Procedure which shows rudimentary operation of TREE DATA STRUCTURE
    Author : Renyavn Liu
    Time : April , 2023 .
*/

#include <stdio.h>
#include <stdlib.h>

tree_node* root ;
root->element = 0 ;
root->head = NULL ;
root->tail = NULL ;
root->node_count = 0 ; //initialize "root".

typedef struct linking_node{
    linking_node* next ; // points to the next node in linked list , content of which is adress of another tree_node.
    tree_node* node ; // points to a tree_node.
}linking_node ;

typedef struct tree_node{
    int element ;
    tree_node* parent ; // points to parent node of this tree_node.
    linking_node* head ;
    linking_node* tail ;
    int node_count ;
}tree_node ;

// this Founction will add a children node for target node:
void increase_node(tree_node* target_node , data ) // data will be assign to value in children node of "node".
{
    linking_node* new_link_node = malloc( 2*sizeof(int) ) ;
    tree_node* new_tree_node = malloc( 5*sizeof(int) ) ; // malloc for two new nodes.

    new_tree_node->element = data ;
    new_tree_node->head = NULL ;
    new_tree_node->tail = NULL ;
    new_tree_node->node_count = 0 ; // initialize tree_node.

    target_node->head = new_link_node ;
    target_node->tail = new_link_node ;
    (target_node->node_count) ++ ; // assign value to target_node.

    
}

int main()
{

}