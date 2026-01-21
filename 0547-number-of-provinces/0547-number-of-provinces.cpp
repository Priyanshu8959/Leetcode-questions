class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        queue<int> q;
        visited[node] = true;
        q.push(node);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (auto &neighbour : adj[current]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        // Correct matrix → list conversion
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        int count = 0;
        vector<bool> visited(n, false);

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                count++;
                bfs(adj, visited, v);
            }
        }
        return count;
    }
};
