class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        long long totalSum = 0;
        for (int x : nums) totalSum += x;

        
        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

         auto genSums = [&](vector<int>& arr) {
            int m = arr.size();
            vector<vector<long long>> sums(m + 1);
            for (int mask = 0; mask < (1 << m); mask++) {
                long long s = 0;
                int bits = __builtin_popcount(mask);
                for (int i = 0; i < m; i++) {
                    if (mask & (1 << i)) s += arr[i];
                }
                sums[bits].push_back(s);
            }
            for (int i = 0; i <= m; i++) {
                sort(sums[i].begin(), sums[i].end());
            }
            return sums;
        };

        auto leftSums = genSums(left);
        auto rightSums = genSums(right);

        long long ans = LLONG_MAX;

        // try every possible subset size k
        for (int k = 0; k <= half; k++) {
            auto& A = leftSums[k];
            auto& B = rightSums[half - k];

            for (long long sumA : A) {
                long long target = totalSum / 2 - sumA;

                // binary search in B
                auto it = lower_bound(B.begin(), B.end(), target);

                if (it != B.end()) {
                    long long picked = sumA + *it;
                    long long diff = llabs(totalSum - 2 * picked);
                    ans = min(ans, diff);
                }
                if (it != B.begin()) {
                    --it;
                    long long picked = sumA + *it;
                    long long diff = llabs(totalSum - 2 * picked);
                    ans = min(ans, diff);
                }
            }
        }

        return (int)ans;
    }
};
