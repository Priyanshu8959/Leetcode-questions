class Solution {
public:
    void fn(vector<vector<int>>& answer, vector<int>& ds,
            int k, int target, int value) {
        // base conditions
        if (target == 0 && ds.size() == k) {
            answer.push_back(ds);
            return;
        }
        if (target < 0 || value > 9 || ds.size() > k)
            return;

        // pick
        ds.push_back(value);
        fn(answer, ds, k, target - value, value + 1);
        ds.pop_back();

        // not pick
        fn(answer, ds, k, target, value + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answer;
        vector<int> ds;
        fn(answer, ds, k, n, 1);
        return answer;
    }
};
