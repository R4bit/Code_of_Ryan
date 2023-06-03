/*
作者：刘稔远  信安221
该C程序展示用 Prim算法 解决 最小生成树 问题
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5
#define NOT_FOUND -1 

//函数声明：

//队列——装载 顶点 的索引
void insert(int);
int removeData(void);
bool isQueueEmpty(void);
//栈
void push(int);
int pop(void);
int peek(void);
bool isStackEmpty(void);
//图
void addVertex(char);
void addEdge(int,int);
void print(int);
int getAdjUnvisitedVertexIndex(int);
//广度/深度优先遍历
void breadthFirstSearch(void);
void depthFirstSearch(void);


//初始化 数据结构变量

//队列
int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;
//栈
int stack[MAX];
int top = -1;
//图
typedef struct Vertex
{
   char label;
   bool visited;
}V ;

//顶点计数器
int vertexCount = 0 ; 
//数组 装载 顶点
V* lstVertices[MAX] ;
//邻接矩阵
int adjMatrix[MAX][MAX] ;


/* 队列函数 */
//入队
void insert(int data)
{
   queue[++rear] = data;
   queueItemCount++;
}
//出队
int removeData()
{
   queueItemCount--;
   return queue[front++]; 
}
//bool队列是否为空
bool isQueueEmpty()
{
   return queueItemCount == 0;
}

/* 栈函数 */
//入栈
void push(int item)
{ 
   stack[++top] = item ;
} 
//出栈
int pop()
{ 
   return stack[top--] ;
}
//栈顶元素
int peek()
{
   return stack[top] ;
}
//bool栈是否为空
bool isStackEmpty()
{
   return top == -1 ;
}

/* 图函数 */
//添加顶点 到 顶点队列
void addVertex(char label)
{
   V* vertex = (V* )malloc(sizeof(V ) ) ;
   vertex->label = label ;
   vertex->visited = false ;// 初始化

   lstVertices[vertexCount++] = vertex ;// 顶点 放入‘数组’
}

//为邻接矩阵 添加部分边框
void addEdge( int start , int end )
{
   adjMatrix[start][end] = 1 ;
   adjMatrix[end][start] = 1 ;
}

//打印顶点元素
void print(int vertexIndex) //（输入其在数组表中的下标）
{
   printf("%c ",lstVertices[vertexIndex]->label);
}

//找 相邻 并且 未被访问 的元素
int getAdjUnvisitedVertexIndex(int vertexIndex)
{
   int i ;

   for( i = 0 ; i < vertexCount ; i ++ )
   {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false )
         return i;
   }
	
   return NOT_FOUND ;
}

//breadth-first traversal
void breadthFirstSearch()
{
   int i ;

   //从数组里第一个顶点出发
   lstVertices[0]->visited = true ;
   print(0) ;

   // enqueue //*vertex index*// in queue
   insert(0) ;

   int unvisitedVertex ; 

   while( !isQueueEmpty() )
   {
      //get the unvisited vertex of vertex which is at front of the queue
      int dequeueVertexIndex = removeData() ; // hold dequeue element.

      //adjacent vertex found
      while( (unvisitedVertex = getAdjUnvisitedVertexIndex(dequeueVertexIndex) ) != NOT_FOUND )
      {    
         lstVertices[unvisitedVertex]->visited = true;
         print(unvisitedVertex);
         insert(unvisitedVertex);        
      }
   }

   //queue is empty, search is completed, reset the visited flag        
   for( i = 0 ; i<vertexCount ; i++ )
   {
      lstVertices[i]->visited = false ;
   }
}

//depth-first traversal
void depthFirstSearch()
{
   int i;

   //mark first node as visited
   lstVertices[0]->visited = true;

   //display the vertex
   print(0);

   //push vertex index in stack
   push(0);

   while( !isStackEmpty() ) 
   {
      //get the unvisited vertex of vertex which is at top of the stack
      int unvisitedVertex = getAdjUnvisitedVertexIndex(peek() ) ;

      //no adjacent vertex found
      if(unvisitedVertex == -1)
      {
         pop() ;
      }
      else
      {
         lstVertices[unvisitedVertex]->visited = true;
         print(unvisitedVertex);
         push(unvisitedVertex);
      }
   }

   //stack is empty, search is complete, reset the visited flag        
   for(i = 0;i < vertexCount;i++)
   {
      lstVertices[i]->visited = false;
   }
}

int main()
{
   int choice ;

   // set adjacency matrix to 0 :
   for( int i=0 ; i < MAX ; i++ ) 
   {
      for( int j=0 ; j < MAX ; j++ )       
         adjMatrix[i][j] = 0;
   }

   // put vertex into an "array" :
   addVertex('A');   // 0
   addVertex('B');   // 1
   addVertex('C');   // 2
   addVertex('D');   // 3
   addVertex('E');   // 4
 
   // add_Edge "1" element at //*both top and bottom*// traingle part of the matrix : 
   addEdge(0, 1);    // A - B
   addEdge(0, 2);    // A - C
   addEdge(0, 3);    // A - D
   addEdge(1, 4);    // B - E
   addEdge(2, 4);    // C - E
   addEdge(3, 4);    // D - E
	
   printf("Your choice( 1 breadth-first-search ; 2 depth-first-search ) : " ) ;
   scanf("%d", &choice) ;
   switch (choice)
   {
   case 1:
      printf("\nBreadth First Search:\n");
      breadthFirstSearch();
      break;
      
   case 2:
      printf("\nDepth First Search:\n");
      depthFirstSearch();
      break;
   
   default:
      break;
   }

   printf("\n");
   // check adjacency matrix
   for( int i = 0 ; i < MAX ; i++ )
   {
      for( int j = 0 ; j < MAX ; j++ )
      {
         printf("%d ", adjMatrix[i][j]);
      }
      printf("\n");
   }

   return 0;
}

