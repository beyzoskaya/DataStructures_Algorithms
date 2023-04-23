from collections import defaultdict
import heapq
def subprime_path(capacity_graph, load_graph, start, end):
   # all the distances are infinity for dijkstra firstly
    distance = [float('inf')] * len(load_graph)
    #starting node has no distance to itself
    distance[start] = 0
    # we need to keep track of previous node because we want to see path at the end 
    previous_node = [None] * len(load_graph)

    # with priority queue, we can detect the visited nodes with their distances
    # initialize the starting node with distance 0
    pri_queue = [(0, start)]

    # up to priority queue is not empty, we have a node to visit
    while pri_queue:
        
        print(f"pri queue {pri_queue}")

        dist, node = heapq.heappop(pri_queue)
        print(f"what is dist {dist}")
        
        #if recently node is end then we stop / termination condition
        if node == end:
            break

        
        if dist > distance[node]:
            continue

        
        # for controlling the values we need to iterate all the neighbours
        for i, (neighbor, edge_weight) in enumerate(load_graph[node]):
            # we have a constraint that we can not add the node which is fully capacitated 
            # # so we can keep the percentage of that value  
            weight_percentage = edge_weight / capacity_graph[node][i][1]
            # if our node is not fully capacitated we can control for distance
            if weight_percentage != 1:

                total_dist = dist + weight_percentage

               # if the updated distance is better than previous one we need to update general distance
                if total_dist < distance[neighbor]:
                    distance[neighbor] = total_dist
                    
                    # for going other nodes we need to update node
                    previous_node[neighbor] = node
                   
                   # add to the heap so we can get the last distance
                    heapq.heappush(pri_queue, (total_dist, neighbor))

  
    if previous_node[end] is None:
        return None

   
    path = []
    node = end
    while node is not None:
        path.append(node)
        node = previous_node[node]
    path.reverse()

    return path, distance[end]




# def subprime_path(capacity_graph, load_graph, start, end):
#      # Create a dictionary to store the minimum capacity percentage for each city
#     min_capacity_percentage = {}
#     # Create a dictionary to store the previous city in the shortest path
#     previous_city = {}
#     # Create a dictionary to store the visited status of each city
#     visited_node = {}

#     # Initialize the starting city with 100% capacity percentage
#     min_capacity_percentage[start] = 1.0
#     # Set the previous city of the starting city to None
#     previous_city[start] = None
#     # Set the visited status of the starting city to False
#     visited_node[start] = False

#     # Initialize the priority queue with the starting city and its capacity percentage
#     pri_queue = [(100.0, start)]

#     # Loop until the priority queue is empty
#     while  pri_queue:
#         # Pop the city with the minimum capacity percentage from the priority queue
#         capacity_percentage, city = pq.heappop(pri_queue)
#         # Mark the city as visited
#         visited_node[city] = True

#         # destination city = end termination
#         if city == end:
#             break

#         # neighboring cities
#         for i, (dest, capacity) in enumerate(capacity_graph[city]):
#             print(f"dest {dest}")
#             # Check if the neighboring city has not been visited
#             if not visited_node.get(dest,False):
#                 # Calculate the current load/capacity percentage
#                 load_percentage = float(load_graph[city][i][1]) / float(capacity) # main cost to check
#                 print(load_graph[city][i][1])
#                 print(f"load_percentage {load_percentage}")
#                 # Check if the load/capacity percentage is not equal to 1 (full capacity loaded)
#                 if load_percentage != 1.0:
#                     print(f"new capacity perc before calculation {capacity_percentage}")
#                     # Calculate the new capacity percentage for the neighboring city
#                     new_capacity_percentage = load_percentage
#                     print(f"new capacity perc after calculation {new_capacity_percentage}")
#                     # Check if the new capacity percentage is greater than the current capacity percentage
#                     if (new_capacity_percentage < min_capacity_percentage[dest]):
#                         # Update the minimum capacity percentage for the neighboring city
#                         min_capacity_percentage[dest] = new_capacity_percentage + min_capacity_percentage[previous_city[city]] 
#                         print(min_capacity_percentage)
#                         # Set the previous city of the neighboring city to the current city
#                         previous_city[dest] = city
#                         # Add the neighboring city to the priority queue with its new capacity percentage
#                         pq.heappush(pri_queue, (new_capacity_percentage, dest))

#     # If the destination city is not reached, return None for both the path and the minimum capacity percentage
#     if end not in previous_city:
#         return None, None

#     # Build the shortest path by traversing the previous cities from the destination city to the starting city
#     path = []
#     city = end
#     while city is not None:
#         path.append(city)
#         city = previous_city[city]
#     path.reverse()
#     print(path)
#     # Return the shortest path and the minimum capacity percentage for the path
#     return path, min_capacity_percentage[end]
#     #print('hello world')

def main():
    c = int(input())
    adjl_capacities = [[] for i in range(c)]
    adjl_loads = [[] for i in range(c)]
    for i in range(c):
        line = input().strip()
        if line.startswith('.'):
            continue
        pairs = line.split(';')
        for p in pairs:
            pair = p.split(',')
            adjl_capacities[i].append((int(pair[0]),int(pair[1])))
    for i in range(c):
        line = input().strip()
        if line.startswith('.'):
            continue
        pairs = line.split(';')
        for p in pairs:
            pair = p.split(',')
            adjl_loads[i].append((int(pair[0]),int(pair[1])))
    start = int(input())
    end=int(input())
    print(subprime_path(adjl_capacities,adjl_loads,start,end))

main()