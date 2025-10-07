#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> st;
    long long minVal;
public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minVal = val;
        } else {
            if (val < minVal) {
                // Store encoded value
                st.push(2LL * val - minVal);
                minVal = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long topVal = st.top();
        st.pop();
        if (topVal < minVal) {
            // Decoding previous min
            minVal = 2LL * minVal - topVal;
        }
    }

    int top() {
        long long topVal = st.top();
        if (topVal < minVal)
            return (int)minVal; // Encoded value case
        return (int)topVal;
    }

    int getMin() {
        return (int)minVal;
    }
};
