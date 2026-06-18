class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int i = 0, j = 0;
        int n = s.size();
        int max_freq = 0;
        int ans = 0;
        while(j<n){
            mp[s[j]]++;
            max_freq = max(max_freq,mp[s[j]]);
            if((j-i+1)-max_freq<=k){
                ans = max(ans,j-i+1);
            }
            else if((j-i+1)-max_freq>k){
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};