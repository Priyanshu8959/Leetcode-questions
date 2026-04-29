class Solution {
public:
bool BFS(vector<vector<int>>& graph,int node,vector<int>&color,int currentcolor){
    color[node]=currentcolor;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int currentnode = q.front();
        q.pop();
        for(auto &it : graph[currentnode]){
            if(color[it]==color[currentnode]){
                return false;
            }
            if(color[it]==-1){
                color[it]=1-color[currentnode];
                q.push(it);
            }
            
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
         int n = graph.size();
        vector<int>color(n,-1);
        int currentcolor = 1;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(BFS(graph,i,color,currentcolor)==false){
                    return false;
                }
            }
             
        }
        return true;
    }
};