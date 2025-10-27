class Solution {
public:
    void backtrack(string &digits, int index, string current, vector<string> &ans,
                   vector<vector<string>> &track) {
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        int num = digits[index] - '0'; // convert char to int
        for (string it : track[num]) {
            backtrack(digits, index + 1, current + it, ans, track);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        vector<vector<string>> track = {
            {}, {}, {"a", "b", "c"}, {"d", "e", "f"},
            {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"},
            {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"}
        };

        backtrack(digits, 0, "", ans, track);
        return ans;
    }
};
