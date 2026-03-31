class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;   // edge case
        
        int ans = 1;
        int i = 0, j = 0;
        int count = 0;

        while(j < nums.size()) {
            ans *= nums[j];

            while(ans >= k) {
                ans /= nums[i];
                i++;
            }

             count += (j - i + 1);

            j++;
        }

        return count;
    }
};