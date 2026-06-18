class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        int sum = 0;int length = INT_MAX;
        while(j<n){
            sum += nums[j];
            
            while(sum>=target){
                length = min(j-i+1,length);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        length =( length==INT_MAX)? 0:length;

        return length;
    }
};