class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n = nums.size();
        int sum= n*(n+1)/2;
        int currentSum=0;
        for(int i=0;i<n;i++){
             currentSum+=nums[i];
        }
        int result = sum - currentSum;
     return result ;
    }
};