#include <iostream>
#include <queue>
using namespace std;

/*
Breadth first search yapıyoruz 
Q ile implement ediyoruz 
source node X'i enqueue ediyoruz queue'ye
X'i visited olarak isaretliyoruz

while Q is not empty
q.dequeue()
*/

class Graph
{
    int V;
    vector<list<int>> adj;

    public :
        Graph(int V);
        void addEdge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // add w to v's list 
}

void Graph::BFS(int s){
    vector<bool> visited;
    visited.resize(V,false); // tüm node'ları unvisited olarak isaretliyoruz

    list<int> queue;

    visited[s] = true; // current node'u visited olarak degistriyoruz
    queue.push_back(s); // queue'ya yeni elemanı koyuyoruz 

    while(!queue.empty()){
        s = queue.front(); // yeni node'u queue'nun basına koyduk!
        cout << s << " ";
        queue.pop_front(); // yeni elemanı sıraya aldıktan sonra remove ediyoruz queue'dan 

            // yeni element'e adjacent olan tüm node'ları tarıyoruz!
            for(auto adjacent : adj[s]){
                if(!visited[adjacent]){
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }


    }

}
