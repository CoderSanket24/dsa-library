# Problem 10: Dijkstra's Shortest Path Algorithm

## Overview
Dijkstra's algorithm finds the shortest path from a source vertex to all other vertices in a weighted graph with non-negative edge weights.

## Key Features
- Finds shortest path in weighted graphs
- Uses priority queue (min-heap)
- Time Complexity: O((V + E) log V)
- Space Complexity: O(V)
- Works with non-negative weights only

## Algorithm Steps
1. Initialize distances: source = 0, others = infinity
2. Use min-heap to process vertices by distance
3. For each vertex, relax all adjacent edges
4. Update distances if shorter path found
5. Repeat until all vertices processed

## Real-World Applications
- GPS Navigation (Google Maps, Waze)
- Network Routing (OSPF protocol)
- Flight route optimization
- Game AI pathfinding
- Social network analysis

## Dijkstra vs BFS
- **Dijkstra**: Considers edge weights, finds minimum weight path
- **BFS**: Ignores weights, finds minimum hop path

## Test Cases
1. Basic weighted graph
2. Specific path finding
3. Comparison with BFS
4. GPS navigation example
5. Disconnected graph handling

## Run
```bash
make examples/problem10_dijkstra
./examples/problem10_dijkstra
```
