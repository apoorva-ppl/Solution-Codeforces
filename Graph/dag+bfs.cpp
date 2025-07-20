#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include<queue>
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Step 1: Create adjacency list & calculate indegree
        for (auto it : prerequisites) {
            int course = it[0];
            int prereq = it[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        // Step 2: Push all nodes with indegree 0 to the queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        // Step 3: Perform BFS and build topological order
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Check if topological sort is valid
        if (topo.size() == numCourses) return topo;
        return {}; // cycle detected 😭
    }
};
