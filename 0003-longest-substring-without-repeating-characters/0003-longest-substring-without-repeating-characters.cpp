class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i=0,j=0;
        //this is quetion of sliding window because this is using lonest word and accodring ro the pattern this is sliding window question 
        unordered_map<int,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                ans=max(ans,j-i+1);
            }
            else if(mp.size()<j-i+1){
               
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};