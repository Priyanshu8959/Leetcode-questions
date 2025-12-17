class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int sum = 0, count = 0;

        for (int x : nums) {
            sum += (x % 2);    

            if (freq.count(sum - k)) {
                count += freq[sum - k];
            }

            freq[sum]++;
        }

        return count;
    }
};
