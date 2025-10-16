class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      unordered_map<int,int>count;
      vector<int>container;
        for(auto i : nums){
            count[i]++;
        }
        for(auto &i:count){
            if(i.second==1){
                container.push_back(i.first);
            }
        }
        return container; 
    }
};