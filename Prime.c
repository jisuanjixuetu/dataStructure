#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_SIZE 100
#define INFINITY 9999999

bool visited[MAX_VERTEX_SIZE] = {false};

typedef struct Enode {
    int v1,v2;
    int weight;
}Enode,*PtrToEnode;

typedef struct Gnode {
    int vernum;
    int edgenum;
    int graph[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE]
}Gnode,*PtrToGnode;
