class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        for (int i = 0; i < n; i++) {
            mp1[nums[i]]++;
        }

        int x = mp1.size();   // total distinct elements

        int i = 0, j = 0;
        long long count = 0;

        while (j < n) {
            mp2[nums[j]]++;

            // when window becomes complete
            while (mp2.size() == x) {
                count += (n - j);   // count all valid subarrays
                mp2[nums[i]]--;
                if (mp2[nums[i]] == 0) {
                    mp2.erase(nums[i]);
                }
                i++;   // shrink from left
            }

            j++;   // expand window
        }

        return count;
    }
};
