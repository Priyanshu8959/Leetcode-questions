class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
      int result = 0;
      if(n==1){
        return nums[0];
      }
      for(int i=0;i<n;i++){
        int current=1;
        for(int j= i;j<n;j++){
            current*=nums[j];
            result = max(current,result);
        }
      } 
      return result; 
    }
};