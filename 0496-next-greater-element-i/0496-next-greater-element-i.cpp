class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextGreater;
        stack<int> st;

        for(int num : nums2){
            while(!st.empty() && num > st.top()){
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Elements left in stack have no greater element
        while(!st.empty()){
            nextGreater[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;
        for(int num : nums1){
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};
