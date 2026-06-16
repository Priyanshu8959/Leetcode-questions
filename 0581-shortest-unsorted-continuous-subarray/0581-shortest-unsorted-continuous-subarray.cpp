class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int l = -1, r = -1;

        // Step 1: find left boundary
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                l = i;
                break;
            }
        }

        // already sorted
        if (l == -1) return 0;

        // Step 2: find right boundary
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                r = i;
                break;
            }
        }

        int mn = nums[l], mx = nums[l];

        for (int i = l; i <= r; i++) {
            if (nums[i] < mn) mn = nums[i];
            if (nums[i] > mx) mx = nums[i];
        }

        // Step 4: expand left boundary
        while (l > 0 && nums[l - 1] > mn) {
            l--;
        }

        // Step 5: expand right boundary
        while (r < n - 1 && nums[r + 1] < mx) {
            r++;
        }

        return r - l + 1;
    }
};