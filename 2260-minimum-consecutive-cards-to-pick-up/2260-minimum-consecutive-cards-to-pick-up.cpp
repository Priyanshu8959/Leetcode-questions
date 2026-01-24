class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        // here used minimun consecutive it meawns it is question of the sliding window
        int i = 0,j = 0;
        int ans = INT_MAX;
        unordered_map<int,int>mp;
        while(j<cards.size()){
           mp[cards[j]]++;
           if(mp.size()<j-i+1){
             
            while(mp.size()<j-i+1){
                mp[cards[i]]--;
                ans = min(ans,j-i+1);
                if(mp[cards[i]]==0){
                    mp.erase(cards[i]);
                }
                i++;
            }
           }
           j++;

        }
        if(ans>cards.size()){
            return -1;
        }
        return ans;
    }
};