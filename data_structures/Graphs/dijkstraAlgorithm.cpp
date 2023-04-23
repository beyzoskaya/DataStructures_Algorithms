#include <iostream>
#include <limits.h>
using namespace std;


// number of verticies in the graph
#define V 9

int minDistance(int dist[], bool sptSet[]){

    int min = INT_MAX, min_index;

    for(int v = 0; v < V; v++)
        if(sptSet[v] == false && dist[v] <= min)
            min = dist[v];
            min_index = v;

            return min_index;
}

void Dijkstra(int graph[V][V], int src){
    int dist[V];
    bool sptSet[V];
    dist[src] = 0;  // Distance of source vertex from itself is always 0

    for(int count = 0; count < V-1; count++){
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;


        for(int v = 0; v < V; v++)

            if(!sptSet[v] && graph[u][v] & dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

}