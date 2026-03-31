class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freqs1(26,0),freqs2(26,0);
        if(s1.size()>s2.size()){
            return false;
        }
        int k = s1.size();
        int i=0,j=0;
        for(int i=0;i<k;i++){
            freqs1[s1[i]-'a']++;
        }
        
        while(j<s2.size())
        {
            freqs2[s2[j]-'a']++;
            if((j-i+1)==k)
            {
                if(freqs1==freqs2){
                    return true;
                }
                else{
                    freqs2[s2[i]-'a']--;
                    i++;
                }
            }
             
            j++;
            }    
           
        return false;
    }
};