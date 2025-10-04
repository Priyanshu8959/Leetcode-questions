class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> righttemp;
        vector<int> ans;
        stack<pair<int, int>> st;
        for (int i = temperatures.size()-1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= st.top().first) {
                st.pop();
            }

            if (st.empty()) {
                righttemp.push_back(-1);
            } else {
                righttemp.push_back(st.top().second);
            }

            st.push({temperatures[i],i});
        }
        reverse(righttemp.begin(), righttemp.end());
        for (int i = 0; i < righttemp.size() ; i++) {
            if (righttemp[i] == -1) {
                ans.push_back(0);
            } else {
                ans.push_back(righttemp[i] - i);
            }
        }
        return ans;
    }
};