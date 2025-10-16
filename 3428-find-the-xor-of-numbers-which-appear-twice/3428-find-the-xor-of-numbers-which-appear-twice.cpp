class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
         unordered_map<int,int>count;
        for(auto i : nums){
            count[i]++;
        }
        vector<int>container;
        for(auto &i:count){
            if(i.second==2){
                container.push_back(i.first);
            }
        }
        int ans = 0;
         for(int i=0;i<container.size();i++){
              ans^=container[i];
         }
         return ans;
    }
};