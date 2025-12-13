class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum = nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            int k = i+1;
            int r = n -1;
            while(k<r){
                int closeS =  nums[k]+nums[i]+nums[r];
                if(abs(target-closeS)<abs(target-sum)){
                    sum = closeS;
                }
                if(closeS<target){
                    k++;
                }
                else{
                    r--;
                }
            }
        }
        return sum;
    }
};