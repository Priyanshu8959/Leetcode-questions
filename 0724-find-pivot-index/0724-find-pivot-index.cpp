class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int sum = 0;
      for(int i=0;i<nums.size();i++){
        sum+=nums[i];
      }  
      int container = 0;
      for(int i = 0;i<nums.size();i++){
          
        if(sum-container-nums[i]==container){
            return i;
        }
        container+=nums[i];
      }
      return -1;
    }
};