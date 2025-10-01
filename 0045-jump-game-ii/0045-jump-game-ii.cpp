class Solution {
public:
    int jump(vector<int>& nums) {

        int count = 0;
        int last = 0;
        int start = 0;
        if (nums.size() < 2) {
            return 0;
        }
        for (int i = 0;i<nums.size()-1;i++) {            
            last=max(last,i+nums[i]);
            if(i==start) {
                count++;
                start = last;
                 
            }
        }
        return count;
    }
};