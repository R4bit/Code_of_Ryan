/*
作者：刘稔远  信安221
该C程序展示用 [Prim算法] 解决 [最小生成树] 问题
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VERTEX_NUM 12
#define NOT_FOUND -1 

////////////////////////////初始化////////////////////////////////////////////////////////

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

   int father ;// 存放父节点在VertexArray的索引值（构造父树时用）
   int distanceToTree ;// 装载 [顶点与树的距离]（定义正无穷值为：-1）
}V ;

// 顶点计数器
int vertexCount = 0 ; 

// [数组] 装载 [顶点]
V* VertexArray[VERTEX_NUM] ;

// [邻接矩阵] 装载 [顶点间边长度]
int adjMatrix[VERTEX_NUM][VERTEX_NUM] ;//表示图
int TreeMatrix[VERTEX_NUM][VERTEX_NUM] ;//表示生成树


////////////////////////////函数声明////////////////////////////////////////////////////////

// 队列
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
void breadthFirstSearch(int);
void depthFirstSearch(int);
int getAdjUnvisitedVertexIndex(int);// core
// 邻接矩阵
void printMatrix(int);
void initializeMatrix();
void initializeTreeMatrix();
void PrimAlgorithm(int);



////////////////////////////函数////////////////////////////////////////////////////////

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
// 2 : 初始化 [顶点到最小生成树的距离] 为 -1（即正无穷）
void addVertex(char label)
{
   V* vertex = (V* )malloc(sizeof(V ) ) ;

   vertex->label = label ;
   vertex->visited = false ;
   vertex->father = -1 ;
   vertex->distanceToTree = -1 ;// 初始化

   VertexArray[vertexCount++] = vertex ;// 顶点 放入[数组]
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
   printf(" %c   ",VertexArray[vertexIndex]->label);
}

//找 相邻 并且 未被访问 的元素
int getAdjUnvisitedVertexIndex(int vertexIndex)
{
   int i ;

   for( i = 0 ; i < vertexCount ; i ++ )
   {
      if(adjMatrix[vertexIndex][i] != -1 && VertexArray[i]->visited == false )
         return i;
   }
	
   return NOT_FOUND ;
}

//广度优先遍历
void breadthFirstSearch( int startVertexIndex )
{
   //从数组里的[指定下标顶点]出发
   VertexArray[startVertexIndex]->visited = true ;
   print( startVertexIndex ) ;
   //将 [顶点的索引] 入队
   insert( startVertexIndex ) ;

   while( !isQueueEmpty() )
   {
      //出队列，找该元素的相邻点
      int dequeueVertexIndex = removeData() ; //装载出队的元素

      int unvisitedVertex ;

      while( (unvisitedVertex = getAdjUnvisitedVertexIndex( dequeueVertexIndex )  )!= NOT_FOUND )//若 找到邻接未访问顶点
      {
         VertexArray[unvisitedVertex]->visited = true;
         print(unvisitedVertex);

         insert(unvisitedVertex); //该元素的下标入队，等待出队时搜寻其相邻未访问元素
      }
   }

   //队列空，搜索完毕，重置顶点数组为未访问状态
   int i ;
   for( i = 0 ; i < vertexCount ; i++ )
   {
      VertexArray[i]->visited = false ;
   }
}

//深度优先遍历
void depthFirstSearch( int startVertexIndex )
{
   //从数组里的[指定下标顶点]出发
   VertexArray[startVertexIndex]->visited = true;
   print( startVertexIndex ) ;

   //入栈
   push( startVertexIndex ) ;

   while( !isStackEmpty() ) 
   {
      //栈顶顶点 的[未访问][邻接]顶点
      int unvisitedVertex = getAdjUnvisitedVertexIndex(peek() ) ;

      //没找到：
      if(unvisitedVertex == -1){
         pop() ;
      }
      //找到了：
      else{
         VertexArray[unvisitedVertex]->visited = true;
         print(unvisitedVertex);
         push(unvisitedVertex);// 其邻接顶点入栈
      }
   }

   //栈空，搜索完毕，重置顶点数组为未访问状态
   int i ;
   for( i = 0 ; i < vertexCount ; i++ )
   {
      VertexArray[i]->visited = false;
   }
}


/* 邻接矩阵操作函数 */

//打印邻接矩阵  0:adjMatrix  1:TreeMatrix
void printMatrix(int choice)
{
   if( choice != 1 && choice != 0 ){
      printf("Error Choice ! \n" ) ;
      return ;
   }
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

      if( choice == 0 ){
         for( int j = 0 ; j < VERTEX_NUM ; j++ )
         {
            if(adjMatrix[i][j] == -1 ){
               printf("[ ]  " ) ;
            }else if(adjMatrix[i][j] >= 10){
               printf("[%d] ", adjMatrix[i][j] ) ;
            }else{
               printf("[%d]  ", adjMatrix[i][j] ) ;
            }
         }
      }else{// choice == 1 
         for( int j = 0 ; j < VERTEX_NUM ; j++ )
         {
            if(TreeMatrix[i][j] == -1 ){
               printf("[ ]  " ) ;
            }else if(TreeMatrix[i][j] >= 10){
               printf("[%d] ", TreeMatrix[i][j] ) ;
            }else{
               printf("[%d]  ", TreeMatrix[i][j] ) ;
            }
         }
      }

      printf("\n") ;
   }
}

//初始化邻接矩阵各项(各边长度)为-1（即无穷大）
void initializeMatrix()
{
   for( int i=0 ; i < VERTEX_NUM ; i++ ) 
   {
      for( int j=0 ; j < VERTEX_NUM ; j++ )       
         adjMatrix[i][j] = -1 ;
   }
}
void initializeTreeMatrix()
{
   for( int i=0 ; i < VERTEX_NUM ; i++ ) 
   {
      for( int j=0 ; j < VERTEX_NUM ; j++ )       
         TreeMatrix[i][j] = -1 ;
   }
}


void PrimAlgorithm( int startVertexIndex )
{
   //将根节点（到最小生成树）距离设置为 0 ， 并添加到树的邻接矩阵
   VertexArray[startVertexIndex]->distanceToTree = 0 ; 
   VertexArray[startVertexIndex]->visited = true ;


   int IndexOfMin = startVertexIndex , unvisitedVertex ;
   int MinDistance = 10000  , i , Index ;
   for( i = 0 ; i < vertexCount-1 ; i ++ )
   {
      //记录相这次被访问节点邻节点的信息（与树距离和父节点）
      while( ( unvisitedVertex = getAdjUnvisitedVertexIndex(IndexOfMin ) ) != NOT_FOUND )
      {
         VertexArray[unvisitedVertex]->distanceToTree = adjMatrix[unvisitedVertex][IndexOfMin] ;

         VertexArray[unvisitedVertex]->father = IndexOfMin ;
      }

      //经过上一步更新记录后，寻找距离生成树距离最小的未访问节点，作为下一步的添加对象
      for( Index = 0 ; Index < vertexCount-1 ; Index ++ )
      {
         if( VertexArray[Index]->visited = false && VertexArray[Index]->distanceToTree < MinDistance )
         {
            MinDistance = VertexArray[Index]->distanceToTree ;
            IndexOfMin = Index ;
         }
      }//现在，temp就是下一步应该添加到树的节点的下标

      //把temp这个选好的节点添加到树的邻接矩阵TreeMatrix :
      addEdge( IndexOfMin , VertexArray[IndexOfMin]->father , VertexArray[IndexOfMin]->distanceToTree ) ;//两个顶点为 temp和temp的父节点

   }
}


int main()
{
   //初始化邻接矩阵 ：
   initializeMatrix() ;

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
   
	int choice ;
   printf("Your choice( 1 breadth-first-search ; 2 depth-first-search ) : " ) ;
   scanf("%d", &choice) ;

   switch (choice)
   {
   case 1:
      printf("\nBreadth First Search(Start at 'A'):\n");
      breadthFirstSearch(0);
      break;
      
   case 2:
      printf("\nDepth First Search(Start at 'A'):\n");
      depthFirstSearch(0);
      break;
   
   default:
      break;
   }
   printf("\n\n\n");


   // 打印原来的邻接矩阵
   printf("Adjacency Matrix :\n") ;
   printMatrix(0) ;

   // 操作：Prim算法找最小生成树
   PrimAlgorithm(0) ;
   printf("\n\n") ;

   // 打印最小生成树在邻接矩阵上的表示
   printMatrix(1) ;


   return 0 ;
}

   /*
   bool AllVisited = true ;
   for( i = 0 ; i < vertexCount ; i ++ )
   {
      if( VertexArray[i]->visited = false )
         AllVisited = false ; //存在未访问顶点，需继续访问
   }
   */
  //判断终止函数