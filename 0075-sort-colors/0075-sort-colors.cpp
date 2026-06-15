class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0; // for zeroes
        int one = 0; // for ones
        int two = 0; // for twos
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
            else if(nums[i]==1){
                one++;
            }
            else{
                two++;
            }
        }
        int index = 0;
        while(zero--){
            nums[index++]=0;
        }
        while(one--){
            nums[index++]=1;
        }
        while(two--){
            nums[index++]=2;
        }
    }
};