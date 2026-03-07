#include "dijkstra.h"

void initializeSingleSource(LGraph* G, PQueue* q, int source)
{
    for(int i = 0; i < G->V; i++)
    {
        minHeapInsert(q, i == source ? 0 : INT_MAX, i);
    }
}

void relax(PQueue* q, int v, int u, int weight)
{
    if(u == INT_MAX)
    {
        return;
    }
    if(q->positions[v] != -1 && q->distances[q->positions[v]] > u + weight)
    {
        heapDecreaseKey(q, q->positions[v], u + weight);
        q->predecessors[q->positions[v]] = u;
    }
}

int* dijkstra(LGraph* G, int source)
{
    int* shortest_paths = (int*) malloc(sizeof(int) * G->V);
    PQueue* q = createPQueue(G->V);
    initializeSingleSource(G, q, source);

    while(q->n > 0)
    {
        int u = q->vertices[0];
        int dist_u = q->distances[0];
        shortest_paths[u] = dist_u;

        heapExtractMin(q);

        Node* node = G->adj[u];
        while(node != NULL)
        {
            relax(q, node->index, dist_u, node->weight);
            node = node->next;
        }
    }
    return shortest_paths;
}

void printDijkstra(int* array, int size, int source)
{
    printf("\nShortest paths for source = %d:\n", source);
    for(int i = 0; i < size; i++)
    {
        
        array[i] < 2000000 ?  printf("%d ", array[i]) : printf("- ");
    }
}