#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INFINITE 99999999
#define MAX_VERTEX_NUM 20
typedef enum
{
    DG,
    DN,
    UDG,
    UGN
} GraphKind;
typedef struct ArcCell
{
    int adj;  // 是否连接
    int info; // 存储的信息权值
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct mGraph
{
    char vex[MAX_VERTEX_NUM]; // 顶点
    AdjMatrix matrix;
    int vexnum; // 顶点数
    int arcnum; // 边数
    GraphKind kind;
} MGraph;

int LocateVertex(MGraph *graph, char point)
{
    // 遍历找到与顶点对应的下标
    for (int i = 0; i < graph->vexnum; i++)
    {
        if (graph->vex[i] == point)
        {
            return i;
        }
    }
}
void CreateDG(MGraph *graph)
{
    char original, terminal; // 弧头和狐尾
    int i, j, k;
    printf("please enter the numner of the vertex and the number of arcs:\n");
    scanf("%d%d", &(graph->vexnum), &(graph->arcnum)); // 读取顶点数和狐数
    for (i = 0; i < graph->vexnum; i++)
    {
        for (j = 0; j < graph->vexnum; j++)
        {
            graph->matrix[i][j].adj = INFINITE; // 初始化
            graph->matrix[i][j].info = 0;
        }
    }
    for (k = 0; k < graph->arcnum; k++)
    {
        printf("please enter the original and the terminal of the vertex:\n");
        scanf("%c %c", &original, &terminal);
        i = LocateVertex(graph, original); // 找到起点的下标
        j = LocateVertex(graph, terminal); // 找到终点的下标
        graph->matrix[i][j].adj = 1;       // 将终点和起点的弧设置为1，表示连接
    }
    printf("the directed graph is finished\n");
}
void CreateUDG(MGraph *graph)
{
    char original, terminal; // 弧头和狐尾
    int i, j, k;
    printf("please enter the number of the vertex and the number of the arcs:\n");
    scanf("%d %d", &(graph->vexnum), &(graph->arcnum)); // 读取顶点数和狐数
    for (i = 0; i < graph->vexnum; i++)
    {
        printf("please enter the %dpoints\n", i + 1);
        scanf("%c", &(graph->vex[i])); // 顶点
    }
    for (i = 0; i < graph->vexnum; i++)
    {
        for (j = 0; j < graph->vexnum; j++)
        {
            graph->matrix[i][j].adj = INFINITE; // 初始化
        }
    }
    for (k = 0; k < graph->arcnum; k++)
    {
        printf("please enter the original and the termian of the %d arc:\n", k + 1);
        scanf("%c %c", &original, &terminal);
        i = LocateVertex(graph, original);
        j = LocateVertex(graph, terminal);
        graph->matrix[i][j].adj = 1;
        graph->matrix[j][i].adj = 1;
    }
    printf("the nudirected graph is finished\n");
}
void CreateDN(MGraph *graph)
{
    char original, terminal;
    int i, j, k;
    int weight;
    printf("please enter the number of the vertex and the number of the arcs:\n");
    scanf("%d %d", &(graph->vexnum), &(graph->arcnum)); // 读取顶点数和狐数
    for (i = 0; i < graph->vexnum; i++)
    {
        printf("please enter the %dpoints\n", i + 1);
        scanf("%c", &(graph->vex[i])); // 顶点
    }
    for (i = 0; i < graph->vexnum; i++)
    {
        for (j = 0; j < graph->vexnum; j++)
        {
            graph->matrix[i][j].adj = INFINITE; // 初始化
            graph->matrix[i][j].info = 0;
        }
    }
    for (k = 0; k < graph->arcnum; k++)
    {
        printf("please enter the original and the termian of the %d arc:\n", k + 1);
        scanf("%c %c", &original, &terminal);
        printf("please enter the weight of the %d arc:\n", k + 1);
        scanf("%d", &weight);
        i = LocateVertex(graph, original);
        j = LocateVertex(graph, terminal);
        graph->matrix[i][j].adj = 1;
        graph->matrix[i][j].info = weight;
    }
    printf("the directed net is finished\n");
}

void CreateUDN(MGraph *graph)
{
    char original, terminal;
    int i, j, k;
    int weight;
    printf("please enter the number of the vertex and the number of the arcs:\n");
    scanf("%d %d", &(graph->vexnum), &(graph->arcnum)); // 读取顶点数和狐数
    for (i = 0; i < graph->vexnum; i++)
    {
        printf("please enter the %dpoints\n", i + 1);
        scanf("%c", &(graph->vex[i])); // 顶点
    }
    for (i = 0; i < graph->vexnum; i++)
    {
        for (j = 0; j < graph->vexnum; j++)
        {
            graph->matrix[i][j].adj = INFINITE; // 初始化
        }
    }
    for (k = 0; k < graph->arcnum; k++)
    {
        printf("please enter the original and the termian of the %d arc:\n", k + 1);
        scanf("%c %c", &original, &terminal);
        printf("please enter the weight of the %d arc:\n", k + 1);
        scanf("%d", &weight);
        i = LocateVertex(graph, original);
        j = LocateVertex(graph, terminal);
        graph->matrix[i][j].adj = 1;
        graph->matrix[j][i].adj = 1;
        graph->matrix[i][j].info = weight;
        graph->matrix[j][i].info = weight;
    }
    printf("the nudirected graph is finished\n");
}

void CreateGraph(MGraph *graph)
{
    int kind;
    printf("please enter the graph that you want to create:\n");
    printf("1.DG,2.UDG,3.DN,4.UDN\n");
    scanf("%d", &kind);
    switch (kind)
    {
    case 1:
        CreateDG(graph);
        break;
    case 2:
        CreateUDG(graph);
        break;
    case 3:
        CreateDN(graph);
        break;
    case 4:
        CreateUDN(graph);
        break;
    default:
        printf("error\n");
    }
}

int main()
{
    MGraph *graph;
    CreateGraph(graph);
    return 0;
}
