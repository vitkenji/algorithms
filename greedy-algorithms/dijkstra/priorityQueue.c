#include "priorityQueue.h"

int heapMinimum(PQueue* q)
{
    if(q->n == 0)
    {
        printf("Empty queue\n");
        exit(1);
    }
    return q->distances[0];
}

int heapExtractMin(PQueue* q)
{
    if(q->n < 1)
    {
        printf("Error: heap underflow\n");
        exit(1);
    }
    int min = q->vertices[0];
    int last_v = q->vertices[q->n - 1];

    q->distances[0] = q->distances[q->n - 1];
    q->vertices[0] = q->vertices[q->n - 1];
    q->predecessors[0] = q->predecessors[q->n - 1];
    
    q->positions[last_v] = 0;
    q->positions[min] = -1;
    q->n--;

    minHeapify(q, 0);
    return min;
}

void heapDecreaseKey(PQueue* q, int index, int key)
{
    if(key > q->distances[index])
    {
        printf("Error: new key is higher than actual key\n");
        exit(1);
    }
    q->distances[index] = key;

    while(index> 0 && q->distances[parent(index)] > q->distances[index])
    {
        swap(q, index, parent(index));
        index = parent(index);
    }
}

void minHeapInsert(PQueue* q, int key, int index)
{
    if(q->n >= q->size)
    {
        printf("Error: heap overflow\n");
        return;
    }
    q->n++;
    q->vertices[q->n - 1] = index;
    q->distances[q->n - 1] = +INT_MAX;
    q->predecessors[q->n - 1] = -1;
    q->positions[index] = q->n - 1;
    heapDecreaseKey(q, q->n - 1, key);
}