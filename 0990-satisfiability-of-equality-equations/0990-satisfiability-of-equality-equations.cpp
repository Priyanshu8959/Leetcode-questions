class Solution {
public:
       vector<int>parent;
       vector<int>rank;
       int find(int node){
        if( parent[node]==node){
            return node;
        } 
        return parent[node]=find(parent[node]);

       }

       void Union(int n1,int n2){
        int p1 =  find(n1);
        int p2 =  find(n2);
        if(p1==p2){
            return ;
        }
        else  if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }
        else if(rank[p2]>rank[p1]){
            parent[p1]=p2;
        }
        else{
            parent[p1]=p2;
            rank[p2]++;
        }

       }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for(int i= 0;i<26;i++){
            parent[i]=i;
            rank[i]=1;
        }
         for(auto &s : equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
         }
         for(auto &s : equations){
            if(s[1]=='!'){
                if(find(s[0]-'a')==find(s[3]-'a')){
                    return false;
                }
            }
         }
return true;
    }
};