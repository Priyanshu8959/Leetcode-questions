class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
       vector<int>ans(nums.size());
       int p=0;
       int n=1;
       for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
            ans[p]=nums[i];
            p+=2;
        }
        else if(nums[i]%2!=0){
            ans[n]=nums[i];
            n+=2;
        }
       }
       return ans; 
    }
};