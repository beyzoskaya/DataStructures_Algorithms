/*
pair-wise relationships
vertes---> nodes
edges---> arcs

directed graph(di-graph) ---> pair of ordered verticies
undirected graph ---> unordered verticies (u,v)/(v,u) are same

social-network
city-road network
prerequsite courses

representing graph:
-adjacency matrix
-adjacency list

Adjacency Matrix
V nodes ---> [V][V] matrix 
remove edges take O(1) time
edge control done in O(1) time
consumes more space ---> O(V)^2


Adjacency List
linked list aracılıgıyla gosteriyoruz
her bir node'un baglı oldugu nodeları arrayde linked list ile baglıyoruz
space req ---> O(|V|+|E|)
edge control ---> O(V)
*/

/*
Breadth-First Traversal 

level by level traverse ediyoruz
since we have cycles each node will be visited infinite times  ----> use a boolean visited array 
visited ---> true
not visited ---> false

*/