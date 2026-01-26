class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp1;
         unordered_map<int,int>mp2;
         for(int i= 0;i<nums.size();i++){
            mp1[nums[i]]++;
         }
         int n = mp1.size();
        int count = 0;
        for(int i=0;i<nums.size();i++){
            for(int j = i;j<nums.size();j++){
                    mp2[nums[j]]++;
                    if(mp2.size()==n){
                        count++;
                    }
            }
            mp2.clear();
        }
          
         return count;
    }
};