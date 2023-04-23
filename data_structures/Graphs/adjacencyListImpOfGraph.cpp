#include <iostream>
using namespace std;

// belli bir uzaklıgı var bir de distance'ı var 
struct AdjListNode{
    int dest;
    struct AdjListNode* next;
};

// for representing adjacency list
struct AdjList
{
    struct AdjListNode* head; // head node of list
};

struct Graph
{
    // number of verticies
    int V;
    struct AdjList* Array; // size of array is V
};

struct AdjListNode* newAdjListNode(int distance)
{
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = distance;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->Array = (struct AdjList*)malloc(sizeof(struct AdjList));

    int i ;

    for(int i =0; i<V; i++)
    graph->Array[i].head = NULL;
        return graph;
}
