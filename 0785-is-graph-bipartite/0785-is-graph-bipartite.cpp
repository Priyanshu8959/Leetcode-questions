class Solution {
public:

    bool DFS(vector<vector<int>>& graph,int node,vector<int>&color,int currentcolor){
        color[node]=currentcolor;
        for(auto it : graph[node]){
            if(color[it]==currentcolor){
                return false;
            }
            if(color[it]==-1){
                if(DFS(graph,it,color,1-currentcolor)==false){
                    return false;
                }
            }
        }
            
       return true; 
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // step1 : graph prepration 
        // unordered_map<int,vector<int>>graph;
        // for(auto it : graph){
        //     graph[it[0]].push_back(it[1]);
        //     graph[it[1]].push_back(it[0]);
        // }

        //step 2 dfs fuction call 
    
        int n = graph.size();
        vector<int>color(n,-1);
        int currentcolor = 1;  // red = 1 and blue = 0
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                 if( DFS(graph,i,color,currentcolor)==false){
                    return false;
                 }
            }
        }
        return true;
    }
};