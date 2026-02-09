class Solution {
public:
    vector<int> parent, rank;

    int find(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void Union(int n1, int n2){
        int p1 = find(n1);
        int p2 = find(n2);

        if(p1 == p2) return;

        if(rank[p1] < rank[p2]){
            parent[p1] = p2;
        }
        else if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        }
        else{
            parent[p2] = p1;
            rank[p1]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        int component = n;

        for(auto &edge : connections){
            if(find(edge[0]) != find(edge[1])){
                Union(edge[0], edge[1]);
                component--;
            }
        }
        return component - 1;
    }
};