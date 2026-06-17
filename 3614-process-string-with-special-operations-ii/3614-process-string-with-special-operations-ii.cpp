class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> length(n);
        long long temp = 0;
        // Cap length at a safe threshold to prevent long long overflow
        long long MAX_LIMIT = 2e18; 

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                temp = max(0LL, temp - 1);
            } else if (s[i] == '#') {
                if (temp > MAX_LIMIT) {
                    temp = MAX_LIMIT;
                } else {
                    temp *= 2;
                }
            } else if (s[i] == '%') {
            } else {
                temp++;
            }
            length[i] = temp;
        }

        if (k < 0 || k >= temp) return '.';

        for (int i = n - 1; i >= 0; i--) {
            long long prev_len = (i > 0) ? length[i - 1] : 0;
            
            if (s[i] == '*') {
                
            } else if (s[i] == '%') {
                long long current_len = length[i];
                if (current_len > 0) {
                    k = current_len - 1 - k;
                }
            } else if (s[i] == '#') {
                if (k >= prev_len) {
                    k -= prev_len;
                }
            } else {
                if (k == prev_len) {
                    return s[i];
                }
            }
        }
        return '.';
    }
};