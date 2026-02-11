# Graph Traversal: BFS and DFS

This program implements Breadth-First Search (BFS) and Depth-First Search (DFS) traversal algorithms on an undirected graph represented using an adjacency matrix.

## Data Structures

The program uses the following data structures to represent and traverse the graph:

- **adj[MAX][MAX]**: A 2D integer array (adjacency matrix) that represents the graph. If `adj[i][j]` is 1, there is an edge between vertex i and vertex j. If it's 0, no edge exists. For an undirected graph, the matrix is symmetric (adj[i][j] = adj[j][i]).

- **visited[MAX]**: A 1D integer array that tracks whether each vertex has been visited during traversal. A value of 1 indicates the vertex has been visited, while 0 means it hasn't been visited yet.

- **n**: An integer variable storing the total number of vertices in the graph.

- **MAX**: A constant defined as 10, representing the maximum number of vertices the graph can have.

- **queue[MAX]**: A local array used in the BFS function to implement a queue for storing vertices to be processed. It uses two indices, front and rear, to manage the queue operations.

## Functions Implemented

### 1. `void BFS(int start)`
**Purpose**: Performs Breadth-First Search traversal starting from a given vertex.

This function implements the BFS algorithm using a queue. It first initializes all vertices as unvisited, then marks the starting vertex as visited and adds it to the queue. The function then enters a loop where it dequeues a vertex, prints it, and enqueues all its unvisited adjacent vertices. This process continues until the queue is empty. BFS explores vertices level by level, visiting all neighbors at the current depth before moving to vertices at the next depth level. The traversal order is printed as the vertices are dequeued.

### 2. `void DFS(int v)`
**Purpose**: Performs Depth-First Search traversal recursively starting from a given vertex.

This is a recursive function that implements the DFS algorithm. It marks the current vertex as visited and prints it immediately. Then it iterates through all vertices to find unvisited adjacent vertices and recursively calls DFS on them. This approach explores as deep as possible along each branch before backtracking. The recursion naturally handles the backtracking mechanism, and the function uses the call stack instead of an explicit stack data structure. DFS explores one path completely before exploring alternative paths.

## Organization of main() Method

The main function demonstrates both graph traversal algorithms through the following steps:

1. **Variable Declaration**: Loop variables i and j are declared for iterating through the adjacency matrix.

2. **Graph Initialization**: The number of vertices is set to 4. The adjacency matrix is initialized to all zeros using nested loops, representing a graph with no edges initially.

3. **Edge Creation**: Edges are added to create an undirected graph. The following edges are created:
   - Edge between vertex 0 and vertex 1
   - Edge between vertex 0 and vertex 2
   - Edge between vertex 1 and vertex 2
   - Edge between vertex 2 and vertex 3
   
   Since the graph is undirected, each edge is represented by setting both adj[i][j] and adj[j][i] to 1.

4. **BFS Execution**: The BFS function is called with starting vertex 0, which traverses and prints the graph in breadth-first order.

5. **Visited Array Reset**: The visited array is reset to all zeros to prepare for the DFS traversal, since both algorithms use the same visited array.

6. **DFS Execution**: A message is printed, then the DFS function is called with starting vertex 0, which traverses and prints the graph in depth-first order.

7. **Program Termination**: Returns 0 to indicate successful execution.

## Sample Output

### Complete Run
```
BFS Traversal: 0 1 2 3 
DFS Traversal: 0 1 2 3 
```

### Graph Structure Visualization
```
The graph created in this program looks like:

    0
   / \
  1---2---3

Vertices: 0, 1, 2, 3
Edges: (0,1), (0,2), (1,2), (2,3)
```

### Explanation of Traversals

**BFS Traversal (0 1 2 3)**:
- Start at vertex 0, mark it visited, add to queue
- Dequeue 0, print it, enqueue its unvisited neighbors: 1 and 2
- Dequeue 1, print it, enqueue its unvisited neighbor: (2 is already visited, skip)
- Dequeue 2, print it, enqueue its unvisited neighbor: 3
- Dequeue 3, print it, no unvisited neighbors
- Queue empty, traversal complete

**DFS Traversal (0 1 2 3)**:
- Start at vertex 0, mark visited, print it
- Recursively visit neighbor 1, mark visited, print it
- From 1, recursively visit neighbor 2, mark visited, print it
- From 2, recursively visit neighbor 3, mark visited, print it
- Backtrack as no unvisited neighbors remain

### Alternative Graph Example

If we modify the graph structure:
```c
// Different edge configuration
adj[0][1] = adj[1][0] = 1;
adj[1][3] = adj[3][1] = 1;
adj[0][2] = adj[2][0] = 1;

Graph:    1---3
         /
        0
         \
          2

BFS Traversal: 0 1 2 3
DFS Traversal: 0 1 3 2
```

The different structure results in different DFS ordering while BFS remains similar due to its level-by-level exploration pattern.
