/*
作者：刘稔远  信安221
该C程序展示用 链表 构建 栈，用逆波兰表示法解决 表达式解析 问题。
*/
#include <stdio.h>
#include <stdlib.h>

//用链表构建栈（链表头作为栈顶） ：
// 第一个栈 ：存放数字
typedef struct int_list_node
{
    int data ;
    struct int_list_node* next ;

}int_node;

int_node int_stack_head ;

//创建一个新的 int 节点 : 
int_ndoe create_int_node( int num )
{
    int_node* new_node = (int_node* )malloc(sizeof(int_node ) ) ;

    new_node->data = num ;
    new_node->next = NULL ;

    return new_node ;
}

void push_int( int num )
{
    int_node new = create_int_node( num ) ;
    new->
}


//主函数 ：
int main()
{


}
