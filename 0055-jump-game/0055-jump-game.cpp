class Solution {
public:
    bool canJump(vector<int>& nums) {
      int right = nums.size()-1;
      if(nums.size()<2){
        return true;
      }
      for(int i =nums.size()-2;i>=0;i--) {
        if(nums[i]+i>=right){
            if(i==0){
                return true;
            }
            else{
                right = i;
            }
        }
         
      }
      return false;
    }
};