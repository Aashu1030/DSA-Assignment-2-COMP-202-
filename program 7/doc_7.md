# Dijkstra's Shortest Path Algorithm

This program implements Dijkstra's algorithm to find the shortest path from a source vertex to all other vertices in a weighted graph represented using an adjacency matrix.

## Data Structures

The program uses the following data structures to represent the graph and compute shortest paths:

- **graph[MAX][MAX]**: A 2D integer array (adjacency matrix) representing a weighted graph. The value at `graph[i][j]` represents the weight of the edge from vertex i to vertex j. A value of 0 indicates no direct edge exists between the vertices.

- **dist[MAX]**: A 1D integer array that stores the shortest distance from the source vertex to each vertex. Initially, all distances are set to infinity (INT_MAX) except the source vertex which is set to 0.

- **visited[MAX]**: A 1D integer array that tracks whether a vertex has been processed and its shortest distance finalized. A value of 1 indicates the vertex is visited, while 0 means it hasn't been processed yet.

- **n**: An integer variable storing the total number of vertices in the graph.

- **src**: An integer variable representing the source vertex from which shortest paths are calculated.

- **MAX**: A constant defined as 10, representing the maximum number of vertices the graph can accommodate.

## Functions Implemented

### 1. `int minDistance(int dist[], int visited[], int n)`
**Purpose**: Finds the unvisited vertex with the minimum distance value.

This function iterates through all vertices to find the one that hasn't been visited yet and has the smallest distance value from the source. It initializes a minimum value to INT_MAX and compares each unvisited vertex's distance against it. When a smaller distance is found, it updates both the minimum value and the index of that vertex. The function returns the index of the vertex with minimum distance, which will be processed next in Dijkstra's algorithm. This greedy selection ensures we always process the closest unvisited vertex.

### 2. `void dijkstra(int graph[MAX][MAX], int n, int src)`
**Purpose**: Implements Dijkstra's algorithm to compute shortest paths from the source vertex to all other vertices.

This is the core function that executes Dijkstra's algorithm. It begins by initializing all distances to infinity and marking all vertices as unvisited, except the source vertex whose distance is set to 0. The algorithm then runs n-1 iterations. In each iteration, it selects the unvisited vertex with minimum distance using the minDistance function, marks it as visited, and updates the distances of all its adjacent unvisited vertices. The distance update follows the relaxation principle: if the path through the current vertex offers a shorter route to a neighbor, that neighbor's distance is updated. The function includes safety checks to ensure we don't process vertices with infinite distance and only consider edges that actually exist (non-zero weight). Finally, it prints a formatted table showing each vertex and its shortest distance from the source.

## Organization of main() Method

The main function orchestrates the program execution through the following steps:

1. **Variable Declaration**: Variables for the number of vertices (n), source vertex (src), and the adjacency matrix (graph) are declared.

2. **Input Number of Vertices**: The program prompts the user to enter the total number of vertices in the graph and reads this value.

3. **Input Adjacency Matrix**: The program prompts for the weighted adjacency matrix. The user enters the weight for each edge, with 0 indicating no direct edge between vertices. Nested loops are used to read the complete n×n matrix row by row.

4. **Input Source Vertex**: The program asks the user to specify which vertex should be used as the starting point for calculating shortest paths.

5. **Execute Dijkstra's Algorithm**: The dijkstra function is called with the graph, number of vertices, and source vertex as parameters. This function computes and displays the shortest distances.

6. **Program Termination**: Returns 0 to indicate successful execution.

## Sample Output

### Run 1: Simple Weighted Graph
```
Enter number of vertices: 5
Enter adjacency matrix (0 if no edge):
0 10 0 5 0
0 0 1 2 0
0 0 0 0 4
0 3 9 0 2
7 0 6 0 0
Enter source vertex: 0

Vertex   Distance from Source
0        0
1        8
2        9
3        5
4        7
```

### Run 2: Four-Vertex Graph
```
Enter number of vertices: 4
Enter adjacency matrix (0 if no edge):
0 4 0 0
0 0 8 0
0 0 0 1
0 0 0 0
Enter source vertex: 0

Vertex   Distance from Source
0        0
1        4
2        12
3        13
```

### Run 3: Connected Graph with Multiple Paths
```
Enter number of vertices: 4
Enter adjacency matrix (0 if no edge):
0 1 4 0
0 0 2 5
0 0 0 1
0 0 0 0
Enter source vertex: 0

Vertex   Distance from Source
0        0
1        1
2        3
3        4
```

### Graph Visualization for Run 1
```
Graph Structure:
        10
    0 -----> 1
    |     3/ | \1
   5|    /   |  
    |  /    2|   
    v /       v
    3 -------> 2
    | \2    9/  \4
   2|   \   /    
    |     \/      
    v      v
    4 <--- 

Edges and Weights:
0 → 1 (10)
0 → 3 (5)
1 → 2 (1)
1 → 3 (2)
2 → 4 (4)
3 → 1 (3)
3 → 2 (9)
3 → 4 (2)
4 → 0 (7)
4 → 2 (6)
```

### Explanation of Shortest Paths (Run 1)

Starting from vertex 0:

- **To vertex 0**: Distance = 0 (source vertex)
- **To vertex 1**: Distance = 8 (path: 0 → 3 → 1, cost: 5 + 3 = 8)
- **To vertex 2**: Distance = 9 (path: 0 → 3 → 1 → 2, cost: 5 + 3 + 1 = 9)
- **To vertex 3**: Distance = 5 (direct path: 0 → 3, cost: 5)
- **To vertex 4**: Distance = 7 (path: 0 → 3 → 4, cost: 5 + 2 = 7)

The algorithm found that even though there's a direct edge from 0 to 1 with weight 10, the shorter path goes through vertex 3 with total cost 8.

### Algorithm Steps for Run 1

1. Initialize: dist[0]=0, all others=∞
2. Process vertex 0: Update dist[1]=10, dist[3]=5
3. Process vertex 3 (min dist=5): Update dist[1]=8, dist[2]=14, dist[4]=7
4. Process vertex 1 (min dist=8): Update dist[2]=9
5. Process vertex 4 (min dist=7): No improvements
6. Process vertex 2 (min dist=9): All vertices processed

Final shortest distances are displayed in the output table.
