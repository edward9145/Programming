class Graph:
    def dijkstra(self, graph, start, goal):
        shortest_dist = {}
        predecessor = {}
        unvisited = graph.copy() # copy graph
        track_path = []

        for node in unvisited:
            shortest_dist[node] = float('inf')
        shortest_dist[start] = 0

        while unvisited:
            min_dist_node = None

            # find current shortest node
            for node in unvisited:
                if min_dist_node is None:
                    min_dist_node = node
                if shortest_dist[node] < shortest_dist[min_dist_node]:
                    min_dist_node = node

            path_options = unvisited[min_dist_node].items()
            for child_node, weight in path_options:
                if weight + shortest_dist[min_dist_node] < shortest_dist[child_node]:
                    shortest_dist[child_node] = weight + shortest_dist[min_dist_node]
                    predecessor[child_node] = min_dist_node

            unvisited.pop(min_dist_node)

        find = goal
        while find != start and find in predecessor:
            track_path.append(find)
            find = predecessor[find]
        
        if find == start:
            track_path.append(start)
            track_path.reverse()
        else:
            print('no path')
            track_path = []
        
        return track_path, shortest_dist[goal]

g= Graph() 

graph = {
'a':{'b':3,'c':4, 'd':7},
'b':{'c':1,'f':5},
'c':{'f':6,'d':2},
'd':{'e':3, 'g':6},
'e':{'g':3, 'h':4},
'f':{'e':1, 'h':8},
'g':{'h':2},
'h':{'g':2},
'i':{}
}
# Print the solution 
path, min_dist = g.dijkstra(graph,'a', 'i') 
print(path, min_dist)

path, min_dist = g.dijkstra(graph,'a', 'h') 
print(path, min_dist)
