class Solution {
public:
void solve(vector<int>& nums, vector<vector<int>>&opt1,vector<int>&opt2,int index){
    if(nums.size()==index){
        opt1.push_back(opt2);
        return;
    }
     solve(nums,opt1,opt2,index+1);
    opt2.push_back(nums[index]);   
   
    solve(nums,opt1,opt2,index+1);
    opt2.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        
         vector<vector<int>>opt1;
        vector<int>opt2;
        solve(nums,opt1,opt2,0);
        return opt1;
    }
};