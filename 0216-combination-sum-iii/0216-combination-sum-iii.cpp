class Solution {
public:
    // essensial things is 1) arr (1 to 9)
    //                     2) k ;
    //                     3) sum which is n
    //                     4) ans vector of string for storing result 
    //                     5) string s for current stirng of nubmers  
    void helper(int k, int sum, vector<vector<int>>&ans,vector<int>&arr,int i,vector<int>&s){
       int n = arr.size();
        
        
       if(sum==0 && k==0){
        ans.push_back(s);
        return;
       } 
       if(k<0 || sum<0 || i==n){
        return ;
       }
       helper(k,sum,ans,arr,i+1,s); //not pick
       s.push_back(arr[i]);
       helper(k-1,sum-arr[i],ans,arr,i+1,s); //pick
       s.pop_back();
        
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>s;
        vector<int>arr={1,2,3,4,5,6,7,8,9};
        helper(k,n,ans,arr,0,s);
        return ans;
    }
};