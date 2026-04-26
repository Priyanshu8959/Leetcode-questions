class Solution {
public:
    void DFS(vector<bool>& visited, unordered_map<int, vector<int>>& adj, 
             int u, int& nodeCount, int& edgeCount) {
        visited[u] = true;
        nodeCount++;
        edgeCount += adj[u].size(); // har node ke edges count karo

        for (auto v : adj[u]) {
            if (!visited[v]) {
                DFS(visited, adj, v, nodeCount, edgeCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto it : edges) {
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodeCount = 0, edgeCount = 0;
                DFS(visited, adj, i, nodeCount, edgeCount);

                // edgeCount/2 because har edge do baar count hua
                if (edgeCount / 2 == nodeCount * (nodeCount - 1) / 2) {
                    count++;
                }
            }
        }
        return count;
    }
};