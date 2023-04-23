#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int vertices; // number of vertices
    list<int>* adjacency; // adjacency list of vertices
    void topologicalSortUtil(int vertice, bool visited[], stack<int>& Stack);

    public:
        // constructor
        Graph(int vertice);
        //function to add an edge to graph
        void addEdge(int v, int w);

        void topologicalSort();
};

Graph::Graph(int V){
    this->vertices = V;
    adjacency = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adjacency[v].push_back(w); // add v to w's list 
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack){
    visited[v] = true; // mark the current node as visited

    list<int>::iterator i;
    for(i=adjacency[v].begin(); i != adjacency[v].end(); ++i)
        if(!visited[*i])
            topologicalSortUtil(*i,visited, Stack);

            Stack.push(v);
}
void Grap::topologicalSort(){
    stack<int> Stack;
    bool* visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

        for(int i=0; i<V; i++)
            if(visited[i] == false)
                topologicalSortUtil(i,visited,Stack);


                while(Stack.empty() == false){
                    cout << Stack.top() << " ";
                    Stack.pop(); 
                }
}