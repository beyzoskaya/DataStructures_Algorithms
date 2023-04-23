from collections import deque

def isInCycle(match_scores,donor_friends,query):
    number_of_recipients = len(match_scores[0]) # match scores length gave the recipient number
    number_of_donors = len(donor_friends) # also donor friends matrix gave the number of donors
    graph = [[]for i in range (number_of_recipients)] # we have a graph nodes are represented with recipients
    # so we need to iterate through recipients
    for donor in range (number_of_donors): #for initialization of friends and match criteria we need to iterate throup donors
        friend = donor_friends[donor] # friends of donor
        for recipient in range(number_of_recipients):
            if friend == recipient and match_scores[donor][recipient] >= 60: # if the match score is greater than or equal and donor's friend is recipient match is successfull
                print("i am in donor")
                pass
            elif match_scores[donor][recipient] >= 60: # if recipient is not friend of donor, we need to control for match scores
                graph[friend].append(recipient)
            
    print(graph)
    adj_matrix = graph
    n = len(adj_matrix)  # number of vertices in the graph --> recipients
    visited_recipient = [False] * number_of_recipients  # to keep track of visited vertices
    # first of all all the nodes are not visited 
    stack = []  # we can keep the visited nodes in stack
    for start in range(query,number_of_recipients): # we need to take which recipient are we in and iterate through recipients for mark the visited nodes
        if not visited_recipient[start]: # if we did not visit the node
            stack.append(start) # add to the stack for visiting
            while stack: # up to stack is not empty 
                print(stack)
                print(visited_recipient)
                vertex = stack.pop() # node is recipient from stack which is visited so we update it to True
                visited_recipient[vertex] = True
                # print(f"graph {graph[vertex]}")
                for neighbor in graph[vertex]: # iterates through neighbors
                    if not visited_recipient[neighbor]:
                        stack.append(neighbor)
                    elif visited_recipient[neighbor] and neighbor == query:
                         print("i am in ")
                         return True
                    # if adj_matrix[vertex][neighbor]:
                    #     # If there is an edge from vertex to neighbor
                    #     if not visited[neighbor]:
                    #         # If neighbor is not visited yet, add it to the stack
                    #         stack.append(neighbor)
                   
    print(visited_recipient)
    return False

def take_input():
    n = int(input()) 
    m = int(input())
    print(f"n {n}")
    print(f"m {m}")
    donor_friends = input().split(',')
    print(f"donor {donor_friends}")
    for i in range(len(donor_friends)):
        donor_friends[i] = int(donor_friends[i])
    match_scores = []
    for i in range(m):
        match_row = input().split(',')
        for j in range(len(match_row)):
            match_row[j] = int(match_row[j])
        match_scores.append(match_row)
    query = int(input())
    print(isInCycle(match_scores,donor_friends,query))


take_input()
