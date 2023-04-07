tree_node* increase_node(tree_node* target_node , int data ) // data will be assign to value in children node of "node".
{
    linking_node* new_link_node = (linking_node* )malloc( sizeof(linking_node) ) ;
    tree_node* new_tree_node = (tree_node* )malloc( sizeof(tree_node) ) ; // malloc for two new nodes.
 
    new_tree_node->element = data ;
    new_tree_node->parent = target_node ;
    new_tree_node->head = NULL ;
    new_tree_node->tail = NULL ;
    new_tree_node->node_count = 0 ; // initialize new tree_node.

    new_link_node->node = new_tree_node ; // core operation
    new_link_node->next = NULL ; // initialize new link_node.
    
    if (!(target_node->head)) {
        target_node->head = new_link_node;
    } else {
        target_node->tail->next = new_link_node;
    }
    target_node->tail = new_link_node;
    target_node->node_count++; // operation at target_node.

    return new_tree_node ;
}