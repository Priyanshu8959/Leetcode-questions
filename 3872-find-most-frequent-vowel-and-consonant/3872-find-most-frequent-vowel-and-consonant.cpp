class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                mp1[s[i]]++;
            }
            else{mp2[s[i]]++;}
             
        }
        int ans=0;
        int result=0;
        for(auto it:mp1){
            ans=max(it.second,ans);
        }
        for(auto it:mp2){
            result=max(it.second,result);
        }
        return ans+result;
    }
};