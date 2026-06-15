class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int count = 0; // count nubmer of subarrays
        int ans = 1;
        int i = 0;
        int j =0;
        int n = nums.size();
        while(j<n){
            ans*=nums[j];
            while(ans>=k){
                ans/=nums[i];
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
};