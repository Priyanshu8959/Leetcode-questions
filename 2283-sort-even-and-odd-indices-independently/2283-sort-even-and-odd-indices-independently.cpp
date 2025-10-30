class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        // Step 1: separate even and odd index elements
        vector<int> even, odd;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }

        // Step 2: sort even ascending, odd descending
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());

         int e = 0, o = 0;
        for (int i = 0; i < n; i++) {
            nums[i] = (i % 2 == 0) ? even[e++] : odd[o++];
        }

        return nums;
    }
};
