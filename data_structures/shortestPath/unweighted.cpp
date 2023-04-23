#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Bellman-Ford ile cözersek ---> O(VE)
Negative edge varsa ----> Dijkstra ---> O(E + VlogV)
graph unweighted oldugu icin ---> O(E+V) zamanda cözülüyo
Breadht-first search yaparken de predecessor tutuyoruz 
array olusturup icine uzaklıklarını verdikten sonra 
O(1) zamanda uzaklıgı alabiliyoruz
en kısa yolu bulmak ise worst case'de O(V)
*/


// utility function to form edge between two vertices
// source and dest
void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool BFS(vector<int> adj[], int src, int dest, int v, int pred[], int dist[])
{
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> enqueue;


    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];

    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for(int i = 0; i <v; i++){
        visited[i] == false;
        dest[i] = INT_MAX;
        pred[i] = -1;
    }
    visited[src] == true;
    dist[src] = 0;
    
    queue.push_back(src);

        while( ! queue.empty())
        {
            int u = queue.front();
            queue.pop_front();

            for(int i=0; i<adj[u].size(); i++){
                if(visited[u][i] == false){
                    visited[u][i] == true;
                    dist[u][i] = dist[u] + 1;
                    pred[adj[u][i]] = u;
                    queue.push_back(adj[u][i]);

                        if(adj[u][i] == dest)
                            return true;
                }
            }

        }
                             return false;   
}