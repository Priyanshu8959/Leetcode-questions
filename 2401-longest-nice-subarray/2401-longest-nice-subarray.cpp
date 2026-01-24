class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int i = 0, j = 0;
        int ans = 0;
        int mask = 0;

        while (j < nums.size()) {

            if ((mask & nums[j]) == 0) {
                // no conflict → directly add
                mask |= nums[j];
                ans = max(ans, j - i + 1);
            }
            else {
                // conflict → remove until safe
                while ((mask & nums[j]) != 0) {
                    mask ^= nums[i];
                    i++;
                }
                mask |= nums[j];
                ans = max(ans, j - i + 1);
            }

            j++;
        }

        return ans;
    }
};
