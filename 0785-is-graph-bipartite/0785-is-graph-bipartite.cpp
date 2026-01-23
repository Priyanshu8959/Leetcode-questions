class Solution {
public:
bool dfscheckforbg(vector<vector<int>>& graph,int node,vector<int>&color,int currentColor){
   color[node]=currentColor;
   
   //neighbour k0 check karte hai 
   for(auto &neighbour : graph[node]){
       //not colored
       if(color[neighbour]==-1){
           int changeINcolor = 1-currentColor;
           if(dfscheckforbg(graph,neighbour,color,changeINcolor)==false)
           return false;
       }
       
       //same color of node
       if(color[neighbour]==color[node]){
           return false;
       }
   }
   return true;
  }
  
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
         // Code here
        //0 --->red and 1-->green
        
        
         
            
        //using DFS
        vector<int>color(V,-1);
        for(int vertax=0;vertax<V;vertax++){
             if(color[vertax]==-1){
                 if(dfscheckforbg(graph,vertax,color,0)==false){
                     return false;
                 }
             }
        }
        return true;
    }
};