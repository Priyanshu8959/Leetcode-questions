class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> mp;

        if (n < 3)
            return 0;

        int i = 0, j = 0, count = 0;

        while (j < n) {
            if (mp.size() < 3) {
                mp[s[j]]++;
                j++;
            }

            while (mp.size() == 3) {
                count += (n - j + 1);

                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        return count;
    }
};
