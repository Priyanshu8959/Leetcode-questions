
class Solution {
public:
void solve(vector<int> nums,vector<int>&ans,vector<vector<int>>&result){
    if(nums.size()==0){
        result.push_back(ans);
        return;
    }
    vector<int>opt1= ans;
    vector<int>opt2 = ans;
    opt2.push_back(nums[0]);
    nums.erase(nums.begin());
    
    solve(nums,opt1,result);
        solve(nums,opt2,result);


}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result ;
        vector<int>ans;
        solve(nums,ans,result);
        return result;

    }
};