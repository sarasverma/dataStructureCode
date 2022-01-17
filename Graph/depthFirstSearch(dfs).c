#include <stdio.h>
#define MAX 30
int adjacentMatrix[MAX][MAX], visited[MAX], nodes;
// no need to create stack as it will done by recurssion itself.

void dfs(int vertex)
{
    printf("%d\t", vertex);
    visited[vertex] = 1;
    for (int i = 1; i <= nodes; i++)
        if ((adjacentMatrix[vertex][i] == 1) && (!visited[i]))
            dfs(i);
}

void main()
{
    int vertex;
    printf("No of nodes :");
    scanf("%d", &nodes);
    // directly enter adjacent matrix
    printf("Enter adjacency matrix :");
    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            scanf("%d", &adjacentMatrix[i][j]);

    for (int i = 1; i <= nodes; i++)
        visited[i] = 0;
    printf("Enter the vertex to start :");
    scanf("%d", &vertex);
    dfs(vertex);
}