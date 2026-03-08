class Solution {
public:
    bool possible(vector<int>& nums, int mid, int threshold) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += (nums[i] + mid - 1) / mid;  // ✅ correct integer ceil
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;  
        int high = *max_element(nums.begin(), nums.end());
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(nums, mid, threshold)) {
                answer = mid;
                high = mid - 1;   
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};