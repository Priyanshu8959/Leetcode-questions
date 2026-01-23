class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> result;
        
        // Build graph
        for (auto &it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);  // b -> a
        }

        // Indegree calculation
        vector<int> indegree(n, 0);
        for (int v = 0; v < n; v++) {
            for (auto &x : adj[v]) {
                indegree[x]++;
            }
        }

        // Push nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS (Kahn's Algorithm)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (auto &neighbour : adj[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        // Check if topological sort is possible
        if (result.size() == n) {
            return result;
        }
        return {};
    }
};
