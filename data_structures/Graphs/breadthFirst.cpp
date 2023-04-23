#include <iostream>
#include <list>
#include <queue>

using namespace std;

void Graph::BFS(int s){

    // mark all the verticies as not visited
    bool *visited = new bool[V];
    for(int i=0; i<V; i++){
        visited[i]= false;
    }

    // create a queue for implementing graph
    list<int> queue;

    // mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s); //(enqueue s)

    // i will be used to get all adjacent vertices of a vertex
    list<int>::iterator i
    while(!queue.empty())
    {
        // dequeue then print
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for(i=adj[s].begin(); i != adj[s].end(); ++i){
            if(!visited[*i]){
                visited[*i] =true;
                queue.push_back(*i);
            }
        }
    }

}

/*
VISITED:
        1 2 3 4 5 6
        |0|0|0|0|0|0|
QUEUE:
        1 2 3 4 5 6
        |0|0|0|0|0|0|

PRINT

all verticies are visited olunca queue bos oluyor zaten !!!!
queue'ya alıp print ediyoruz sonra dequeue yapıyoruz

time complexity ----> 0(V+E)
*/

/*
Shortest Path in undirected graph



*/