class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;

        int i = 0, j = 0;
        int count = mp.size();
        int minLen = INT_MAX;
        int start = 0;

        while (j < s.size()) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    count--;
            }

            while (count == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        count++;
                }
                i++;
            }
            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
