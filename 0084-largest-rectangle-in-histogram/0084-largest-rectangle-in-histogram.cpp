class Solution {
public:
    // Next smaller to right -> gives index
    vector<int> nextSmallerRight(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n); // default n if no smaller to right
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    // Next smaller to left -> gives index
    vector<int> nextSmallerLeft(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1); // default -1 if no smaller to left
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right = nextSmallerRight(heights);
        vector<int> left = nextSmallerLeft(heights);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }
};
