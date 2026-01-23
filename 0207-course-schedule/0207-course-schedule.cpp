class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count = 0;
        vector<vector<int>>adj(numCourses);
        for(auto &it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>indegree(numCourses,0);
        //indegree calculation
        for(int vertax =0;vertax<numCourses;vertax++){
            for(auto &it : adj[vertax]){
                indegree[it]++;
            }
        }

        //insert in queue whose n degree is 0
        queue<int>q;
        for(int vertax = 0;vertax<numCourses;vertax++){
            if(indegree[vertax]==0){
                q.push(vertax);
                count++;
            }
        }

        //insertion in queue
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &neigbours : adj[node]){
                indegree[neigbours]--;
                if(indegree[neigbours]==0){
                    count++;
                    q.push(neigbours);
                }
            }
        }
        if(numCourses==count){
            return true;
        }
        return false;
         }
};