class Solution {
public:
     int AUH(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n, n);  // next smaller to right
        vector<int> left(n, -1);  // next smaller to left
        stack<int> st;

         for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

         for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, arr[i] * width);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> v(m, 0);
        int mx = 0;

         for (int j = 0; j < m; j++) {
            v[j] = (matrix[0][j] == '1') ? 1 : 0;
        }
        mx = AUH(v);

         for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    v[j] = 0;
                } else {
                    v[j] += 1; 
                }
            }
            mx = max(mx, AUH(v));
        }

        return mx;
    }
};
