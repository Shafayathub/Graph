# Graphs in C++

## Introduction
A **Graph** is a data structure that consists of nodes (vertices) and edges that connect them. It is widely used to represent networks like social connections, transportation systems, and web pages.

## Types of Graphs
1. **Directed Graph (Digraph)** - Edges have a direction.
2. **Undirected Graph** - Edges do not have a direction.
3. **Weighted Graph** - Edges have weights (costs).
4. **Unweighted Graph** - Edges do not have weights.
5. **Cyclic Graph** - Graph with at least one cycle.
6. **Acyclic Graph** - Graph with no cycles.

## Graph Representation in C++

### 1. Adjacency Matrix
```cpp
#include <iostream>
using namespace std;

#define V 5 // Number of vertices

void printGraph(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    printGraph(graph);
    return 0;
}
```

### 2. Adjacency List
```cpp
#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    vector<int> adj[5];
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printGraph() {
        for (int i = 0; i < 5; i++) {
            cout << i << " -> ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.printGraph();
    return 0;
}
```

## Graph Traversal

### 1. Breadth-First Search (BFS)
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<int> adj[], int start, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

### 2. Depth-First Search (DFS)
```cpp
#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(vector<int> adj[], vector<bool> &visited, int node) {
    visited[node] = true;
    cout << node << " ";
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(adj, visited, neighbor);
        }
    }
}

void dfs(vector<int> adj[], int V, int start) {
    vector<bool> visited(V, false);
    dfsHelper(adj, visited, start);
}
```

## Shortest Path Algorithms

### 1. Dijkstra's Algorithm
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

void dijkstra(vector<pair<int, int>> adj[], int V, int src) {
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, src});
    dist[src] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> Distance: " << dist[i] << endl;
    }
}
```

## Graph Cycle Detection

### 1. Cycle Detection in Undirected Graph (DFS)
```cpp
bool isCyclicDFS(int v, vector<int> adj[], vector<bool> &visited, int parent) {
    visited[v] = true;
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            if (isCyclicDFS(neighbor, adj, visited, v)) return true;
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}
```

## Resources
- [Graph Algorithms (GeeksforGeeks)](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)
- [Graph Theory (MIT OpenCourseWare)](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/)
- [Graph Implementation in C++ (YouTube)](https://www.youtube.com/watch?v=ZBHKZF5w4YU)

---
📌 *This file serves as a quick revision guide for Graphs in C++. Feel free to contribute or suggest improvements!* 🚀
