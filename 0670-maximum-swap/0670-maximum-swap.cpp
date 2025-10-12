class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> ans(n);

        ans[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (numStr[i] > numStr[ans[i + 1]]) {
                ans[i] = i;
            } else {
                ans[i] = ans[i + 1];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (numStr[i] < numStr[ans[i]]) {
                swap(numStr[i], numStr[ans[i]]);
                return stoi(numStr);
            }
        }

        return num;
    }
};
