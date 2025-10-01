class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> mp;
     unordered_map<int,int> emp;
    for(auto it:arr){
        mp[it]++;
    }  
    for(auto it:mp){
       emp[it.second]++;  
    }
    for(auto it:emp){
        if(it.second>=2){
            return false;
        }  
    }
    return true;
    }
};