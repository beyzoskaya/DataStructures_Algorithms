
#include <iostream>
using namespace std;

void APUtil(vector<int> adj[], int u, bool visited[], int disc[], int low[], int &time, int parent, bool isAP)
{
    // Count of children in DFS Tree
    int children = 0;

    // Mark the current node as visited
    visited[u] = true;

    disc[u] = low[u] = ++time;

    // Go through all vertices adjacent to this
    for(auto v : adj[u]){
        if(!visited[v]){
            children++;
            APUtil(adj, v,visited,disc,low,time,u,isAP);
        }
    }

}