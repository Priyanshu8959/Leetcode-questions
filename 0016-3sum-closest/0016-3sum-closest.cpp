class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            int left = i+1;
            int right = n-1;
            while(left<right){
                int closest = nums[left]+nums[right]+nums[i];
                if(abs(closest-target)<abs(target-sum)){
                    sum = closest;
                }


                if(closest>target ){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return sum;
    }
};