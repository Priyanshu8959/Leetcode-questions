class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> storage;
        deque<int> dq;
        int n = nums.size();
        int i = 0, j = 0;

        while (j < n) {
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);

            if (dq.front() <= j - k) {
                dq.pop_front();
            }

            if (j - i + 1 < k) {
                j++;
            } 
            else if (j - i + 1 == k) {
                storage.push_back(nums[dq.front()]);
                i++;
                j++;
            }
        }

        return storage;
    }
};
