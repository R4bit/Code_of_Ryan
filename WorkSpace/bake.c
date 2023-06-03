/*
作者：刘稔远  信安221
该C程序展示用 [Prim算法] 解决 [最小生成树] 问题
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VERTEX_NUM 12
#define NOT_FOUND -1 

// 函数声明：

// 队列——装载 顶点 的索引
void insert(int);
int removeData(void);
bool isQueueEmpty(void);
// 栈
void push(int);
int pop(void);
int peek(void);
bool isStackEmpty(void);
// 图
void addVertex(char);
void addEdge(int,int,int);
void print(int);
int getAdjUnvisitedVertexIndex(int);
// 广度/深度 优先遍历
void breadthFirstSearch(void);
void depthFirstSearch(void);


// 初始化 [数据结构变量]

// 队列
int queue[VERTEX_NUM];
int rear = -1;
int front = 0;
int queueItemCount = 0;
// 栈
int stack[VERTEX_NUM];
int top = -1;
// 图
typedef struct Vertex
{
   char label ;
   bool visited ;
   struct Vertex* father ;// 指向该节带点的父节点（构造父树时用）
   int distanceToTree ;// 装载 [顶点与树的距离]（定义正无穷值为：-1）
}V ;

// 顶点计数器
int vertexCount = 0 ; 

// [数组] 装载 [顶点]
V* lstVertices[VERTEX_NUM] ;

// [邻接矩阵] 装载 [顶点间边长度]
int adjMatrix[VERTEX_NUM][VERTEX_NUM] ;


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

// 1 : 添加 [顶点] 到 [顶点‘数组’]
// 2 : 添加 [顶点到最小生成树的距离] 到 [距离数组]
void addVertex(char label)
{
   V* vertex = (V* )malloc(sizeof(V ) ) ;
   vertex->label = label ;
   vertex->visited = false ;
   vertex->father = NULL ;// 初始化

   lstVertices[vertexCount++] = vertex ;// 顶点 放入‘数组’


}

//为两个顶点 添加 边
void addEdge( int start , int end , int len )
{
   adjMatrix[start][end] = len ;
   adjMatrix[end][start] = len ;
}

//打印顶点元素
void print(int vertexIndex) //（输入其在V*顶点数组表中的下标）
{
   printf(" %c   ",lstVertices[vertexIndex]->label);
}

//找 相邻 并且 未被访问 的元素
int getAdjUnvisitedVertexIndex(int vertexIndex)
{
   int i ;

   for( i = 0 ; i < vertexCount ; i ++ )
   {
      if(adjMatrix[vertexIndex][i] != 0 && lstVertices[i]->visited == false )
         return i;
   }
	
   return NOT_FOUND ;
}

//广度优先遍历
void breadthFirstSearch()
{
   int i ;

   //从数组里第一个顶点出发
   lstVertices[0]->visited = true ;
   print(0) ;
   //将顶点的索引 入队
   insert(0) ;

   while( !isQueueEmpty() )
   {
      //出队列，找该元素的相邻点
      int dequeueVertexIndex = removeData() ; //装载出队的元素

      int unvisitedVertex ;

      while( (unvisitedVertex = getAdjUnvisitedVertexIndex( dequeueVertexIndex )  )!= NOT_FOUND )//若 找到邻接未访问顶点
      {    
         lstVertices[unvisitedVertex]->visited = true;
         print(unvisitedVertex);

         insert(unvisitedVertex); //该元素的下标入队，等待出队时搜寻其相邻未访问元素
      }
   }

   //队列空了，搜索完毕，重置顶点数组为未访问状态
   for( i = 0 ; i < vertexCount ; i++ )
   {
      lstVertices[i]->visited = false ;
   }
}

//深度优先遍历
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

//打印邻接矩阵
void printMatrix()
{
   printf("   A    B    C    D    E    F    G    H    I    J    K    L\n") ;
   for( int i = 0 ; i < VERTEX_NUM ; i++ )
   {
      switch ( i )
      {
      case 0 :
         printf("A ") ;
         break;
      case 1 :
         printf("\nB ") ;
         break;
      case 2 :
         printf("\nC ") ;
         break;
      case 3 :
         printf("\nD ") ;
         break;
      case 4 :
         printf("\nE ") ;
         break;
      case 5 :
         printf("\nF ") ;
         break;
      case 6 :
         printf("\nG ") ;
         break;
      case 7 :
         printf("\nH ") ;
         break;
      case 8 :
         printf("\nI ") ;
         break;
      case 9 :
         printf("\nJ ") ;
         break;
      case 10 :
         printf("\nK ") ;
         break;
      case 11 :
         printf("\nL ") ;
         break;
      default:
         break;
      }

      for( int j = 0 ; j < VERTEX_NUM ; j++ )
      {
         if(adjMatrix[i][j] == 0 ){
            printf("[ ]  " ) ;
         }else if(adjMatrix[i][j] >= 10){
            printf("[%d] ", adjMatrix[i][j] ) ;
         }else{
            printf("[%d]  ", adjMatrix[i][j] ) ;
         }
      }
      printf("\n");
   }
}

int main()
{
   int choice ;

   //初始化邻接矩阵 ：
   for( int i=0 ; i < VERTEX_NUM ; i++ ) 
   {
      for( int j=0 ; j < VERTEX_NUM ; j++ )       
         adjMatrix[i][j] = 0;
   }

   //添加顶点到‘数组’：
   addVertex('A'); // 0
   addVertex('B'); // 1
   addVertex('C'); // 2
   addVertex('D'); // 3
   addVertex('E'); // 4
   addVertex('F'); // 5
   addVertex('G'); // 6
   addVertex('H'); // 7
   addVertex('I'); // 8
   addVertex('J'); // 9
   addVertex('K'); // 10
   addVertex('L'); // 11

   //添加边 ：
   addEdge( 0, 1 , 20 );    // A - B
   addEdge( 0, 3 , 21 );    // A - D
   addEdge( 1, 2 , 7 );     // B - C
   addEdge( 1, 3 , 13 );    // B - D
   addEdge( 1, 4 , 5 );     // B - E
   addEdge( 2, 4 , 1 );     // C - E
   addEdge( 3, 4 , 10 );    // D - E
   addEdge( 3, 5 , 14 );    // D - F
   addEdge( 4, 5 , 22 );    // E - F
   addEdge( 4, 6 , 15 );    // E - G
   addEdge( 4, 7 , 6 );     // E - H
   addEdge( 5, 6 , 4 );     // F - G
   addEdge( 6, 7 , 11 );    // G - H
   addEdge( 6, 8 , 3 );     // G - I
   addEdge( 6, 9 , 19 );    // G - J
   addEdge( 7, 8 , 2 );     // H - I
   addEdge( 7, 10 , 8 );    // H - K
   addEdge( 7, 11 , 9 );    // H - L
   addEdge( 8, 9 , 18 );    // I - J
   addEdge( 8, 10 , 12 );   // I - K
   addEdge( 9, 10 , 17 );   // J - K
   addEdge( 10, 11 , 16 );  // K - L
   
	
   printf("Your choice( 1 breadth-first-search ; 2 depth-first-search ) : " ) ;
   scanf("%d", &choice) ;
   switch (choice)
   {
   case 1:
      printf("\nBreadth First Search(Start at 'A'):\n");
      breadthFirstSearch();
      break;
      
   case 2:
      printf("\nDepth First Search(Start at 'A'):\n");
      depthFirstSearch();
      break;
   
   default:
      break;
   }

   printf("\n\n\n");

   // check adjacency matrix
   printf("Adjacency Matrix :\n") ;
   printMatrix() ;

   return 0 ;
}

