# Programmers - Minimum Cost to Share a Ride

This repository provides two C++ solutions to the **Shared Taxi Fare** problem from [Programmers](https://school.programmers.co.kr/learn/courses/30/lessons/72413), using **Dijkstra's algorithm** and **graph traversal**.

It includes:
- A **C++17+ version** with modern syntax
- A **C++14-compatible version** using traditional syntax

## Problem Description

Two people start from the same location and wish to reach their respective destinations while minimizing the **total taxi fare**.  
They may **share a taxi for a portion of the journey** and split at some node.

### Constraints:
- The graph is **undirected** and **weighted**
- Nodes are labeled from `1` to `n`
- The goal is to find the **minimum value of**:

Total Fare = (S → X) + (X → A) + (X → B)

for all possible split points `X`.

### Input:
- `n`: number of nodes
- `s`: starting point
- `a`, `b`: destinations
- `fares`: list of bidirectional roads with costs

---
