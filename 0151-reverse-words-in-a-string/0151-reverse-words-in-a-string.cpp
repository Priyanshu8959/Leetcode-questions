class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int left = 0, right = 0, i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            if (i == n){
                break;
            }
                 

            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            reverse(s.begin() + left, s.begin() + right);

            s[right++] = ' ';
            left = right;
        }

        if (right > 0 && s[right - 1] == ' ')
            right--;
        s.resize(right);
        return s;
    }
};
