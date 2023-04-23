#include <iostream>
#include <list>
#include <stack>

using namespace std;

/*
not possible if the graph is not a Directed Acylic Graph
*/

class Graph
{
    int V; // no of verticies
    list<int>* adj; //adjacency list
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);
   
    public:
        Graph(int V); // constructor
        void addEdge(int v, int w); //add an edge to the graph
        void topologicalSort(); 
};

void Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack)
{
    // current node ---> visited!!!
    visited[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            topologicalSortUtil(*i,visited,Stack);

            Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;

    // mark all the verticies as not visited
    bool* visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

        for(int i=0; i<V; i++)
            if(visited == false)
                topologicalSortUtil(i,visited,Stack);

                while(Stack.empty() == false)
                {
                    cout << Stack.top() << " ";
                    cout << endl;
                    Stack.pop();
                }
}
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
  
    cout << "Following is a Topological Sort of the given graph n";
    g.topologicalSort();
  
    return 0;
}