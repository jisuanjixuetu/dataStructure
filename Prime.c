#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 50
typedef struct ArcCell
{
    int adj;
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
    int vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum, arcnum;
} MGraph;
typedef struct
{
    int adjvex;
    int lowcost;
} CLOSEDGE;
int total;
void init(MGraph *graph, int an, int vn)
{
    int i, j;
    graph->arcnum = an;
    graph->vexnum = vn;
    for (i = 0; i < vn; i++)
    {
        graph->vexs[i] = i;
        for (j = 0; j < vn; j++)
        {
            graph->arcs[i][j].adj = 99999;
        }
    }
}
int m(CLOSEDGE *closedge, int vexnum)
{
    int i, j = 99999, k;
    for (i = 0; i < vexnum; i++)
    {
        if (closedge[i].lowcost != 0 && closedge[i].lowcost < j)
        {
            j = closedge[i].lowcost;
            k = i;
        }
    }
    if (j == 99999)
        return -1;
    else
    {
        total += j;
        return k;
    }
}
void s(MGraph *graph, int u)
{
    int i, j, k;
    CLOSEDGE closedge[MAX_VERTEX_NUM];
    k = u;
    for (i = 0; i < graph->vexnum; i++)
        if (i != k)
        {
            closedge[i].adjvex = k;
            closedge[i].lowcost = graph->arcs[k][i].adj;
        }
    closedge[k].lowcost = 0;
    for (i = 1; i < graph->vexnum; i++)
    {
        k = m(closedge, graph->vexnum);
        printf("%d -- %d\n", closedge[k].adjvex, graph->vexs[k]);
        closedge[k].lowcost = 0;
        for (j = 0; j < graph->vexnum; ++j)
            if (k != j && graph->arcs[k][j].adj < closedge[j].lowcost)
            {
                closedge[j].adjvex = graph->vexs[k];
                closedge[j].lowcost = graph->arcs[k][j].adj;
            }
    }
}
int main()
{
    MGraph graph;
    int i, arcnum, vexnum;
    int tt[11][3] = {{0, 4, 14}, {0, 1, 19}, {0, 6, 18}, {1, 2, 5}, {1, 3, 7}, {1, 4, 12}, {2, 3, 3}, {3, 4, 8}, {3, 5, 21}, {4, 6, 16}, {5, 6, 27}};
    vexnum = 7;
    arcnum = 11;
    init(&graph, arcnum, vexnum);
    for (i = 0; i < arcnum; i++)
    {
        graph.arcs[tt[i][0]][tt[i][1]].adj = graph.arcs[tt[i][1]][tt[i][0]].adj = tt[i][2];
    }
    total = 0;
    s(&graph, 0);
    printf("total=%d\n", total);
    return 0;
}