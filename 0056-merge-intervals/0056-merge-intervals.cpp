class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>>ans;
        int x = 0 ;
        int x1 = 1 ;
        if(n==1){
            return intervals;
        }
        while(x<n && x1<n){
            if(intervals[x1][0]>intervals[x][1]){
                 ans.push_back({intervals[x][0],intervals[x][1]});
                  x=x1;
                  
            }
            else if(intervals[x1][0]<=intervals[x][1]){
                intervals[x][1]=max(intervals[x1][1],intervals[x][1]);
                 
                  
            }
            x1++;
        }
        ans.push_back(intervals[x]);
        return ans;
    }
};