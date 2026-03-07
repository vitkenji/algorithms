#include "heap.h"

PQueue* createPQueue(int size)
{
    PQueue* q = (PQueue*) malloc(sizeof(PQueue));
    q->distances = (int*) malloc(sizeof(int) * size);
    q->vertices = (int*) malloc(sizeof(int) * size);
    q->predecessors = (int*) malloc(sizeof(int) * size);
    q->positions = (int*) malloc(sizeof(int) * size);
    q->size = size;
    q->n = 0;

    for(int i = 0; i < q->size; i++)
    {
        q->positions[i] = -10;
    }

    return q;
}

int parent(int i)
{
    return((i - 1) / 2);
}

int left(int i)
{
    return(2 * i + 1);
}

int right(int i)
{
    return (2 * i + 2);
}

void minHeapify(PQueue* q, int index)
{
    int l = left(index);
    int r = right(index);
    int smallest;

    if(l < q->n && q->distances[l] < q->distances[index]) // which is smaller: left or parent
    {
        smallest = l;
    }
    else
    {
        smallest = index;
    }

    if(r < q->n && q->distances[r] < q->distances[smallest]) // which is the smallest: left, right or parent
    {
        smallest = r;
    }

    if(smallest != index)
    {
        swap(q, smallest, index); // the smallest goes to parent position
        minHeapify(q, smallest); 
    }
}

void buildMinHeap(PQueue* q)
{
    for(int i = (q->n / 2) - 1; i >= 0; i--)
    {
        minHeapify(q, i);
    }
}

void swap(PQueue* q, int pos1, int pos2)
{
    int aux = q->distances[pos1];
    int aux_index = q->vertices[pos1];
    int aux_pred = q->predecessors[pos1];

    q->distances[pos1] = q->distances[pos2];
    q->vertices[pos1] = q->vertices[pos2];
    q->predecessors[pos1] = q->predecessors[pos2];

    q->distances[pos2] = aux;
    q->vertices[pos2] = aux_index;
    q->predecessors[pos2] = aux_pred;

    q->positions[q->vertices[pos1]] = pos1;
    q->positions[q->vertices[pos2]] = pos2;
}

void printPQueue(PQueue* q)
{
    printf("\nPriority Queue:\n");
    
    printf("\nPositions:  ");
    for(int i = 0; i < q->size; i++)
    {
        if(q->positions[i] != -10)
        {
            printf("%d ", q->positions[i]);
        }
    }

    printf("\nVertices:   ");
    for(int i = 0; i < q->n; i++)
    {
        printf("%d ", q->vertices[i]);
    }
    printf("\nDistances:  ");
    for(int i = 0; i < q->n; i++)
    {
        printf("%d ", q->distances[i]);
    }
    //printf("\nPredecessors:  ");
    for(int i = 0; i < q->n; i++)
    {
        //printf("%d ", q->predecessors[i]);
    }
    printf("\n\n");
}