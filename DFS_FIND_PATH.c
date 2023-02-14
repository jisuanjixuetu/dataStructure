#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX_NUM 20
bool visited[MAX_VERTEX_NUM] = {false};
typedef struct arcNode
{
    int adjvex;              // 该弧指向的顶点的信息
    struct arcNode *nextarc; // 指向下一条弧的指针
    int *info;               // 该弧相关信息的指针
} ArcNode;
typedef struct vNode
{
    int data;          // 顶点信息
    ArcNode *firstarc; // 指向第一条依附该顶点的弧的指针
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct alGraph
{
    AdjList vertices;   // 每一个顶点
    int vexnum, arcnum; // 顶点数，弧数
    int kind;           // 图的种类
} AlGraph;
int Locate_vex(AlGraph *graph, int vertext)
{
    for (int i = 0; i < graph->vexnum; i++)
    {
        if (graph->vertices[i].data == vertext)
        {
            return i;
        }
    }
}
void CreateGraph(AlGraph *graph)
{
    ArcNode *temp = NULL;
    int vertex;  // 弧头
    int vertail; // 狐尾
    int i, j, k;
    printf("pkease enter the name of the vertexs of the graph:\n");
    for (i = 0; i < graph->vexnum; i++)
    {
        scanf("%d", &(graph->vertices[i].data));
        getchar();
        graph->vertices[i].firstarc = NULL;
    }
    printf("please entet the vertex and the vertail of the each arc:\n");
    for (k = 1; k <= graph->arcnum; k++)
    {
        printf("please enter the %d arc vertail and vertail\n");
        scanf("%d %d", &vertail, &vertex);
        getchar();
        i = Locate_vex(graph, vertail);
        j = Locate_vex(graph, vertex);
        temp = (ArcNode *)malloc(sizeof(ArcNode));
        temp->adjvex = j;
        temp->nextarc = graph->vertices[i].firstarc;
        graph->vertices->firstarc = temp;
    }
}
void PrintGraph(AlGraph *graph){
    int i;
    ArcNode *temp = NULL;
    for (i = 0; i < graph->vexnum; i++){
        printf("%d\t",graph->vertices[i].data);
    }
    printf("\n");
    for (i = 0; i < graph->vexnum; i++) {
        printf("%d ->",graph->vertices[i].data);
        temp = graph->vertices[i].firstarc;
        while (temp) {
            printf("%d ",graph->vertices[temp->adjvex].data);
            temp = temp->nextarc;
        }
        printf("\n");
    }
    printf("\n");
}
bool DFS_FIND_PATH(AlGraph *graph,int i,int k){
    ArcNode *p;
    if(i == k){
        return true;
    }
    else {
        visited[i] = true;
        for(p = graph->vertices[i].firstarc; p!=NULL;p = p->nextarc){
            int j = p->adjvex;
            if(!visited[j]&&DFS_FIND_PATH(graph,j,k)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    AlGraph *graph;
    printf("AdjList to store:\n");
    printf("please enter the number of the vertexs:\n");
    scanf("%d",&graph->vexnum);
    printf("please enter the number of the arcnum:\n");
    scanf("%d",&graph->arcnum);
    CreateGraph(graph);
    PrintGraph(graph);
    printf("\n");
    printf("please enter the two point you want to find the path:\n");
    int i,j;
    scanf("%d %d",&i,&j);
    int a = Locate_vex(graph,i);
    int b = Locate_vex(graph,j);
    if(DFS_FIND_PATH(graph,a,b)){
        printf("the path exists\n");
    }
    else {
        printf("the path does not exist\n");
    }
    return 0;
}
