class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0; int j = 0;
        int n = fruits.size();
        unordered_map<int,int>mp;
        int maxfruit = 0;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                maxfruit = max(maxfruit,j-i+1);
            }
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                 i++;
            }
            j++;
        }
        return maxfruit;
    }
};