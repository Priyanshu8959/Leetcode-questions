class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        int evenidx=0;
        int oddidx = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                ans[evenidx]=nums[i];
                evenidx+=2;
            }
             else{
                ans[oddidx]=nums[i];
                oddidx+=2;
             }
        }
        return ans;
    }
};