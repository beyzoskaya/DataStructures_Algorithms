#include <iostream>
#include <queue>
#include <limits.h>
#include <string.h>

using namespace std;

// number of verticies 6 
#define V 6

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited,0,sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s]= -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

            for(int v = 0; v < V; v++){
                if(visited[v] == false && rGraph[u][v] > 0){
                    if(v == t){
                        parent[v] = u;
                        return true;
                    }

                    q.push(v);
                    parent[v] = u;
                    visited[v] = false;
                    }
                }
        }
    // We didn't reach sink in BFS starting from source, so
    // return false
    return false;
}

int fordFulkerson(int graph[V][V], int s, int t)
{
    int rGraph[V][V];

        for(u = 0; u< V; u++)
            for(v = 0; v < V; v++)
                rGraph[u][v] = graph[u][v];

                int parent[V];
                int max_flow = 0;

                while(bfs(rGraph,s,t,parent)){
                    int path_flow = INT_MAX;
                        for(v = t; v != s; v = parent[v]){
                            u = parent[v];
                            
                        }
                }
}