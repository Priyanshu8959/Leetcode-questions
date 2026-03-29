class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        int i =0,j = 1,count=0;
        int diff = nums[j]-nums[j-1];
        j++;
        while(j<nums.size()){
            if(nums[j]-nums[j-1]==diff ){
                if(j-i+1>=3){
                    count+=(j-i-1);
                }
                
            }
            else{
                diff = nums[j]-nums[j-1];
                i = j-1 ;
            }
            j++;
        }
        return count;
    }
};