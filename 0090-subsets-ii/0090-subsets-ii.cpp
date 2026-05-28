class Solution {
public:

    void solve(vector<int>& nums,
               vector<vector<int>>& ans,
               vector<int>& subans,
               int start) {

        // current subset is valid
        ans.push_back(subans);

        for (int i = start; i < nums.size(); i++) {

            // skip duplicates at same level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            // choose
            subans.push_back(nums[i]);

            // recurse
            solve(nums, ans, subans, i + 1);

            // backtrack
            subans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subans;

        solve(nums, ans, subans, 0);

        return ans;
    }
};