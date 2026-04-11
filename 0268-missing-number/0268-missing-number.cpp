class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int currentsum = 0;
        for(auto it:nums){
            currentsum +=it;
        }
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int ans = sum - currentsum;
        return ans;
    }
};