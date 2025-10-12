class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long sum = 0, ans = 0;
        int i = 0, j = 0;

        while(j < nums.size()){
            freq[nums[j]]++;
            sum += nums[j];

            if(j - i + 1 < k){
                j++;
            }
            else if(j - i + 1 == k){
                if(freq.size() == k){   
                    ans = max(ans, sum);
                }
                
                 freq[nums[i]]--;
                if(freq[nums[i]] == 0) freq.erase(nums[i]);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};
