# TREECOLOR

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Distinct colors in subtrees

Given an undirected connected tree with $N$ coloured nodes (colours denoted with integers $1$ to $N$), numbered from $1$ to $N$, and rooted at node $1$. Your task is to determine, for each node, the number of distinct colours present in its subtree.

For example, a subtree rooted at a specific node might contain several nodes with duplicate colors. You must count only the unique colors present in that entire subtree (including the root of that subtree).

## Function Declaration
### Function Name

$distinctColorsInSubtrees$ – This function computes the number of distinct colors in the subtree of every node in the given tree.

### Parameters
- $N$ : An integer representing the total number of nodes in the tree.
- $C$ : A list/array of integers of length $N$, where $C[i]$ represents the color of the $(i+1)^{th}$ node (assuming 0-indexed arrays for colors and 1-indexed nodes).
- $edges$ : A 2D list/array of size $(N-1) \times 2$ representing the undirected edges of the tree, where each pair $(u, v)$ indicates an edge between node $u$ and node $v$.
### Return Value

Returns a list/array of integers of length $N$: The $i^{th}$ element in the returned array should represent the total number of distinct colors in the subtree rooted at node $i+1$.

### Constraints:
- $1 \leq N \leq 10^5$
- $1 \leq C[i] \leq N$ for each $0 \leq i < N$
- $1 \leq u, v \leq N$
- The given edges are guaranteed to form a valid connected tree.
- The sum of $N$ over all test cases won't exceed $5 \cdot 10^5$.

 **The input and output formats provided below are only for testing with custom inputs. You only need to return the value. Printing is handled automatically** 

### Input Format
- The first line of the input contains a single integer $N$ — the number of nodes.
- The second line contains $N$ space separated integers $C_i$ - the colour of ith node.
- The next $N - 1$ lines describe the edges. The $i$-th of these $N - 1$ lines contains two space-separated integers $u_i$ and $v_i$, denoting a bidirectional edge between $u_i$ and $v_i$.
### Output Format
- Output on the single line, $N$ space separated integers, the no. of distinct coloured nodes in the subtree of node $i$ ($1 \leq i \leq N$).
### Sample 1:
Input
Output

```
7
1 2 3 4 3 4 5
1 2
1 7
1 5
2 4
2 3
5 6
```

```
5 3 1 1 2 1 1
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-02T14:29:23.459Z  

```c_cpp
#include <bits/stdc++.h>

unordered_set<int> dfs(int node, int parent, const vector<int>& C, const vector<vector<int>>& adj, vector<int>& ans){
    unordered_set<int> mySet;
    mySet.insert(C[node - 1]);
    for(int child : adj[node]){
        if(child != parent){
            unordered_set<int> childSet = dfs(child, node, C, adj, ans);
            if(childSet.size() > mySet.size()){
                swap(mySet, childSet);
            }
            for(int color : childSet){
                mySet.insert(color);
            }
        }
    }
    ans[node - 1] = mySet.size();
    return mySet;
}

vector<int> distinctColorsInSubtrees(int N, vector<int>& C, vector<vector<int>>& edges) {
    vector<vector<int>> adj(N + 1);
    for(auto& e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<int> ans(N);
    dfs(1, 0, C, adj, ans);
    return ans;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/TREECOLOR)