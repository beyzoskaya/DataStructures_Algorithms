#include <iostream>
using namespace std;

/*
we will try to execute those nodes that have outdegree 0

pseudecode:

for each node in Nodes
    indegree[node] == 0

    for each edge(src, dest) in Edges
        indegree[dest]++

        for each node in Nodes
            if(list[node].size()!=0) then
            for each dest in list
            indegree[dest]++;
*/

class Graph
{
    int V; // number of vertices
    list<int>* adj; // adjacency list for verticies

    public:
    Graph(int V); // constructor
    void addEdge(int u, int v);
    void topologicalSort();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::topologicalSort()
{
    // creates a vector to store indegrees of all vertices --> initialize all indegrees as 0
    vector<int> in_degree(V,0);


    // traverse adjacency list to fill indegrees of vertices ---> O(V+E)
    for(int u=0; u < V; u++){
        list<int>::iterator itr;
            for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
                in_degree[*itr]++;
    }

    queue<int> q;
    for(int i=0; i<V; i++)
        if(in_degree == 0)
            q.push(i);

            int count = 0;
            vector<int> top_order; // topological order result ---> keeping in vector

            while(!q.empty()){
                int u = q.front();
                q.pop();
                top_order.push_back(u);
                
            }

}

    
