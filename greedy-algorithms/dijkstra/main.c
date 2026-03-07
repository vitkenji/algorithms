#include "dijkstra.h"

void test_case_0()
{
  //expected result: 0 8 9 13 7 8 10 5
    LGraph* g = create_L(8);
    insertEdge_L(g, 0, 1, 10); insertEdge_L(g, 0, 7, 5);
    insertEdge_L(g, 1, 2, 1);  insertEdge_L(g, 1, 7, 2);
    insertEdge_L(g, 2, 3, 4);
    insertEdge_L(g, 3, 2, 6);  insertEdge_L(g, 3, 4, 7);
    insertEdge_L(g, 4, 5, 1);  insertEdge_L(g, 4, 3, 9);
    insertEdge_L(g, 5, 6, 2);
    insertEdge_L(g, 6, 4, 4);  insertEdge_L(g, 6, 0, 7); insertEdge_L(g, 6, 2, 3);
    insertEdge_L(g, 7, 1, 3);  insertEdge_L(g, 7, 2, 9); insertEdge_L(g, 7, 4, 2);
    printDijkstra(dijkstra(g, 0), g->V, 0);
}

void test_case_1()
{
     //expected result: 10 5 8 8 0 9 12 11 14 14 16 17 19 21 26 27 30 34 36 42
    LGraph* G = create_L(20);

    insertEdge_L(G, 4, 0, 10);
    insertEdge_L(G, 4, 1, 5);
    insertEdge_L(G, 4, 2, 8);

    insertEdge_L(G, 1, 3, 3);
    insertEdge_L(G, 1, 5, 7);

    insertEdge_L(G, 3, 6, 4);
    insertEdge_L(G, 3, 7, 6);

    insertEdge_L(G, 5, 7, 2);
    insertEdge_L(G, 5, 8, 5);

    insertEdge_L(G, 7, 9, 3);
    insertEdge_L(G, 6, 9, 4);

    insertEdge_L(G, 8, 10, 6);
    insertEdge_L(G, 9, 10, 2);

    insertEdge_L(G, 10, 11, 3);
    insertEdge_L(G, 11, 12, 4);

    insertEdge_L(G, 12, 13, 2);
    insertEdge_L(G, 13, 14, 5);

    insertEdge_L(G, 14, 15, 1);
    insertEdge_L(G, 15, 16, 3);

    insertEdge_L(G, 16, 17, 4);
    insertEdge_L(G, 17, 18, 2);

    insertEdge_L(G, 18, 19, 6);

    insertEdge_L(G, 2, 5, 1);
    insertEdge_L(G, 0, 6, 2);
    insertEdge_L(G, 6, 8, 2);
    insertEdge_L(G, 8, 11, 3);
    insertEdge_L(G, 7, 12, 8);

    printDijkstra(dijkstra(G,4), G->V,4);

}

void test_case_2()
{
    //expected result: 0 - - - - - 2 - 4 6 8 7 11 13 18 19 22 26 28 34
    LGraph* G = create_L(20);

    insertEdge_L(G, 4, 0, 10);
    insertEdge_L(G, 4, 1, 5);
    insertEdge_L(G, 4, 2, 8);

    insertEdge_L(G, 1, 3, 3);
    insertEdge_L(G, 1, 5, 7);

    insertEdge_L(G, 3, 6, 4);
    insertEdge_L(G, 3, 7, 6);

    insertEdge_L(G, 5, 7, 2);
    insertEdge_L(G, 5, 8, 5);

    insertEdge_L(G, 7, 9, 3);
    insertEdge_L(G, 6, 9, 4);

    insertEdge_L(G, 8, 10, 6);
    insertEdge_L(G, 9, 10, 2);

    insertEdge_L(G, 10, 11, 3);
    insertEdge_L(G, 11, 12, 4);

    insertEdge_L(G, 12, 13, 2);
    insertEdge_L(G, 13, 14, 5);

    insertEdge_L(G, 14, 15, 1);
    insertEdge_L(G, 15, 16, 3);

    insertEdge_L(G, 16, 17, 4);
    insertEdge_L(G, 17, 18, 2);

    insertEdge_L(G, 18, 19, 6);

    insertEdge_L(G, 2, 5, 1);
    insertEdge_L(G, 0, 6, 2);
    insertEdge_L(G, 6, 8, 2);
    insertEdge_L(G, 8, 11, 3);
    insertEdge_L(G, 7, 12, 8);

    printDijkstra(dijkstra(G,0), G->V,0);
}

void test_case_3()
{
    //expected result: - - 0 - - 1 - 3 6 6 8 9 11 13 18 19 22 26 28 34 - - - - -
    LGraph* G = create_L(25);

    insertEdge_L(G, 4, 0, 10);
    insertEdge_L(G, 4, 1, 5);
    insertEdge_L(G, 4, 2, 8);
    insertEdge_L(G, 1, 3, 3);
    insertEdge_L(G, 1, 5, 7);
    insertEdge_L(G, 3, 6, 4);
    insertEdge_L(G, 3, 7, 6);
    insertEdge_L(G, 5, 7, 2);
    insertEdge_L(G, 5, 8, 5);
    insertEdge_L(G, 7, 9, 3);
    insertEdge_L(G, 6, 9, 4);
    insertEdge_L(G, 8, 10, 6);
    insertEdge_L(G, 9, 10, 2);
    insertEdge_L(G, 10, 11, 3);
    insertEdge_L(G, 11, 12, 4);
    insertEdge_L(G, 12, 13, 2);
    insertEdge_L(G, 13, 14, 5);
    insertEdge_L(G, 14, 15, 1);
    insertEdge_L(G, 15, 16, 3);
    insertEdge_L(G, 16, 17, 4);
    insertEdge_L(G, 17, 18, 2);
    insertEdge_L(G, 18, 19, 6);
    insertEdge_L(G, 2, 5, 1);
    insertEdge_L(G, 0, 6, 2);
    insertEdge_L(G, 6, 8, 2);
    insertEdge_L(G, 8, 11, 3);
    insertEdge_L(G, 7, 12, 8);

    printDijkstra(dijkstra(G, 2), G->V, 2);
}

void test_case_4()
{
    LGraph* G = create_L(50);

    for(int i = 0; i < 49; i++) {
        insertEdge_L(G, i, i + 1, 2);
    }

    insertEdge_L(G, 0, 10, 5);
    insertEdge_L(G, 10, 25, 10);
    insertEdge_L(G, 25, 40, 5);

    printDijkstra(dijkstra(G, 0), G->V, 0);
}

int main()
{
    test_case_4();
    return 0;
}