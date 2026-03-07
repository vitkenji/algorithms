#include "graph.h"
#include "priorityQueue.h"

void initializeSingleSource(LGraph* G, PQueue* q, int source);
void relax(PQueue* q,int v, int u, int weight);
int* dijkstra(LGraph* G, int source);

void printDijkstra(int* array, int size, int source);