class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> ans;

         for (auto it : nums) {
            mp[it]++;
        }

         vector<vector<int>> help(n + 1);
        for (auto it : mp) {
            help[it.second].push_back(it.first);
        }

         for (int i = n; i >= 0 && ans.size() < k; i--) {
            for (auto it : help[i]) {
                ans.push_back(it);
                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};
