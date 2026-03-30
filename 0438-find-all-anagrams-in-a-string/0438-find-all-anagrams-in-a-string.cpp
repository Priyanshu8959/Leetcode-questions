class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i = 0, j = 0;
        int n = s.size();
        
        vector<int> ans;
        vector<int> freqP(26, 0), freqS(26, 0);

         for (char c : p) {
            freqP[c - 'a']++;
        }

        int k = p.size();

        while (j < n) {
             freqS[s[j] - 'a']++;

             if (j - i + 1 < k) {
                j++;
            }
            
            else if (j - i + 1 == k) {
                 
                if (freqS == freqP) {
                    ans.push_back(i);
                }

                
                freqS[s[i] - 'a']--;
                i++;
                j++;
            }
        }

        return ans;
    }
};