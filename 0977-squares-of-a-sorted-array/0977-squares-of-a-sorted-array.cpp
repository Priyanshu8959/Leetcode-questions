class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
          int n = nums.size();
                   vector<int>ans(n);

         int i = 0;
         int j = n-1;
         int k = j;
         while(i<=j){
            long long squar_i = nums[i]*nums[i];
            long long squar_j = nums[j]*nums[j];
            if(squar_i>squar_j){
                ans[k]=squar_i;
                k--;
                i++;
            }
            else{
                ans[k]=squar_j;
                k--;
                j--;
            }
         }
         return ans;
    }
};