class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;

        for (int end = 0; end <= n; end++) {
            if (end == n || s[end] == ' ') {
               
                int left = start, right = end - 1;
                while (left < right) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                start = end + 1;  
            }
        }
        return s;
    }
};
