class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
     int n =     isConnected.size();
        visited[node] = true;

        for (int neighbours = 0; neighbours < n; neighbours++) {
            if (!visited[neighbours] && isConnected[node][neighbours] == 1) {
                dfs(isConnected, visited, neighbours);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0; // for counting number of provience
        vector<bool> visited(n, false);
        for (int vertax = 0; vertax < n; vertax++) {
            if (!visited[vertax]) {
                count++;
                dfs(isConnected, visited, vertax );
            }
        }
        return count;
    }
};