#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define VERTEX_NUM 12
#define NOT_FOUND -1

// 顶点
typedef struct Vertex
{
    char label;
    bool visited;
    int father;
    int distanceToTree;
} V;

// 图
typedef struct Graph
{
    int vertexCount;
    V **vertices;
    int **adjMatrix;
    int **treeMatrix;
} Graph;

// 创建图
Graph *createGraph()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertexCount = 0;
    graph->vertices = (V **)malloc(VERTEX_NUM * sizeof(V *));
    graph->adjMatrix = (int **)malloc(VERTEX_NUM * sizeof(int *));
    graph->treeMatrix = (int **)malloc(VERTEX_NUM * sizeof(int *));
    for (int i = 0; i < VERTEX_NUM; i++)
    {
        graph->vertices[i] = NULL;
        graph->adjMatrix[i] = (int *)malloc(VERTEX_NUM * sizeof(int));
        graph->treeMatrix[i] = (int *)malloc(VERTEX_NUM * sizeof(int));
        for (int j = 0; j < VERTEX_NUM; j++)
        {
            graph->adjMatrix[i][j] = -1;
            graph->treeMatrix[i][j] = -1;
        }
    }
    return graph;
}

// 添加顶点到图
void addVertex(Graph *graph, char label)
{
    V *vertex = (V *)malloc(sizeof(V));
    vertex->label = label;
    vertex->visited = false;
    vertex->father = -1;
    vertex->distanceToTree = -1;
    graph->vertices[graph->vertexCount++] = vertex;
}

// 添加边到图
void addEdge(Graph *graph, int start, int end, int len)
{
    graph->adjMatrix[start][end] = len;
    graph->adjMatrix[end][start] = len;
}

// 打印邻接矩阵
void printMatrix(int **matrix)
{
    printf("   A    B    C    D    E    F    G    H    I    J    K    L\n");
    for (int i = 0; i < VERTEX_NUM; i++)
    {
        switch (i)
        {
        case 0:
            printf("A ");
            break;
        case 1:
            printf("\nB ");
            break;
        case 2:
            printf("\nC ");
            break;
        case 3:
            printf("\nD ");
            break;
        case 4:
            printf("\nE ");
            break;
        case 5:
            printf("\nF ");
            break;
        case 6:
            printf("\nG ");
            break;
        case 7:
            printf("\nH ");
            break;
        case 8:
            printf("\nI ");
            break;
        case 9:
            printf("\nJ ");
            break;
        case 10:
            printf("\nK ");
            break;
        case 11:
            printf("\nL ");
            break;
        default:
            break;
        }

        for (int j = 0; j < VERTEX_NUM; j++)
        {
            if (matrix[i][j] == -1)
            {
                printf("[ ]  ");
            }
            else if (matrix[i][j] >= 10)
            {
                printf("[%d] ", matrix[i][j]);
            }
            else
            {
                printf("[%d]  ", matrix[i][j]);
            }
        }
    }
    printf("\n");
}

// 获取最小生成树中的下一个顶点
int getNextVertex(Graph *graph)
{
    int minDistance = INT_MAX;
    int nextVertex = NOT_FOUND;
    for (int i = 0; i < graph->vertexCount; i++)
    {
        V *vertex = graph->vertices[i];
        if (vertex->visited)
            continue;

        if (vertex->distanceToTree != -1 && vertex->distanceToTree < minDistance)
        {
            minDistance = vertex->distanceToTree;
            nextVertex = i;
        }
    }
    return nextVertex;
}

// Prim算法
void primAlgorithm(Graph *graph)
{
    int startVertex = 0; // 从第一个顶点开始
    graph->vertices[startVertex]->visited = true;
    graph->vertices[startVertex]->distanceToTree = 0;

    while (true)
    {
        int currentVertex = getNextVertex(graph);
        if (currentVertex == NOT_FOUND)
            break;

        graph->vertices[currentVertex]->visited = true;

        // 更新最小生成树的邻接矩阵
        if (graph->vertices[currentVertex]->father != -1)
        {
            int row = graph->vertices[currentVertex]->father;
            int col = currentVertex;
            int distance = graph->adjMatrix[row][col];
            graph->treeMatrix[row][col] = distance;
            graph->treeMatrix[col][row] = distance;
        }

        for (int i = 0; i < graph->vertexCount; i++)
        {
            V *vertex = graph->vertices[i];
            if (!vertex->visited && graph->adjMatrix[currentVertex][i] != -1)
            {
                if (vertex->distanceToTree == -1 || graph->adjMatrix[currentVertex][i] < vertex->distanceToTree)
                {
                    vertex->distanceToTree = graph->adjMatrix[currentVertex][i];
                    vertex->father = currentVertex;
                }
            }
        }
    }
}

int main()
{
    Graph *graph = createGraph();

    // 添加顶点
    addVertex(graph, 'A');
    addVertex(graph, 'B');
    addVertex(graph, 'C');
    addVertex(graph, 'D');
    addVertex(graph, 'E');
    addVertex(graph, 'F');
    addVertex(graph, 'G');
    addVertex(graph, 'H');
    addVertex(graph, 'I');
    addVertex(graph, 'J');
    addVertex(graph, 'K');
    addVertex(graph, 'L');

    // 添加边
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 4);
    addEdge(graph, 2, 5, 3);
    addEdge(graph, 2, 6, 4);
    addEdge(graph, 3, 7, 2);
    addEdge(graph, 4, 7, 4);
    addEdge(graph, 5, 8, 3);
    addEdge(graph, 5, 9, 4);
    addEdge(graph, 6, 10, 2);
    addEdge(graph, 7, 11, 5);

    printf("原始邻接矩阵：\n");
    printMatrix(graph->adjMatrix);

    primAlgorithm(graph);

    printf("最小生成树的邻接矩阵：\n");
    printMatrix(graph->treeMatrix);

    return 0;
}
