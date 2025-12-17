class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         auto atMost = [&](int k) {
            int res = 0;
            int i = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] % 2 != 0) k--;
                while (k < 0) {
                    if (nums[i] % 2 != 0) k++;
                    i++;
                }
                res += (j - i + 1);
            }
            return res;
        };
         return atMost(k) - atMost(k - 1);
    }
};
