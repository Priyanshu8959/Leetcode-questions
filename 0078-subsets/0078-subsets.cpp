class Solution {
public:
void help(vector<int>&subans,vector<vector<int>>&ans,vector<int>& nums,int i){
    if(i==nums.size()){
        ans.push_back(subans);
        return ;
    }
    help(subans,ans,nums,i+1); // not pick 

    subans.push_back(nums[i]);
    help(subans,ans,nums,i+1);
    subans.pop_back();

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subans;
        help(subans,ans,nums,0);
        return ans;
    }
};