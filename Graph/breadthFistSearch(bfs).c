#include <stdio.h>

#define MAX 30
#define intial 0
#define waiting 1
#define visited 2

int queue[MAX], state[MAX], adjacentMatrix[MAX][MAX];
int front = -1, rear = -1, nodes, edges;

void enqueue(int vertex)
{
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    else
        return queue[front++];
}

void bfs(int vertex)
{
    enqueue(vertex);
    state[vertex] = waiting;

    while (vertex != -1)
    {
        vertex = dequeue();
        if (vertex != -1)
        {
            printf("%d\t", vertex);
            state[vertex] = visited;
        }
        for (int i = 1; i <= nodes; i++)
        {
            if ((adjacentMatrix[vertex][i] == 1) && (state[i] != 2))
            {
                enqueue(i);
                state[i] = waiting;
            }
        }
    }
}

int main()
{
    int u, v, vertex;
    printf("Enter the no of vertices and edges :");
    scanf("%d %d", &nodes, &edges);
    // for edges(filling adjacent matrix)
    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge :");
        scanf("%d %d", &u, &v);
        adjacentMatrix[u][v] = 1;
    }
    for (int i = 1; i <= nodes; i++)
        state[i] = intial;
    printf("Enter vertex to start:");
    scanf("%d", &vertex);
    bfs(vertex);
    return 0;
}