class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int ans =0;
        int n= nums.size();
        for(int j=0;j<n;j++)
        {   ans = 0;
             for(int i=j;i<nums.size();i++){
             ans +=nums[i];
             if(ans == k){
                count++;
             }             
        }
        }
        
        return count;
    }
};