class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;

         
        for(int x : nums) {
            mp[x]++;
        }

         
        int maxfreq = 0;
        for(auto &it : mp) {
            maxfreq = max(maxfreq, it.second);
        }

        
        int ans = 0;
        for(auto &it : mp) {
            if(it.second == maxfreq) {
                ans += it.second;
            }
        }

        return ans;
    }
};
