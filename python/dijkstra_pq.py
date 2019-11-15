class Graph:
    def dijkstra(self, graph, start, goal):
        dist = { node: float("inf") for node in graph }
        prev = {}
        import queue as Q
        pq = Q.PriorityQueue()
        dist[start] = 0
        pq.put((dist[start], start))
        while not pq.empty():
            _, node = pq.get()
            adj_nodes = graph[node]
            for v in adj_nodes:
                if dist[v] > dist[node] + adj_nodes[v]:
                    dist[v] = dist[node] + adj_nodes[v]
                    pq.put((dist[v], v))
                    prev[v] = node
        
        node = goal
        path = [goal]
        while node in prev:
            node = prev[node]
            path.insert(0, node)

        return path, dist[goal]
    
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
path, min_dist = g.dijkstra(graph,'a', 'f') 
print(path, min_dist)

path, min_dist = g.dijkstra(graph,'a', 'h') 
print(path, min_dist)
