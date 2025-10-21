class Solution {
public:
    void fn(vector<vector<int>>& answer, vector<int>& ds,
            vector<int>& candidates, int target, int index) {
        // base condition
        if (index == candidates.size()) {
            if (target == 0) {
                answer.push_back(ds);
            }
            return;
        }

        // pick and not pick condition
        if (candidates[index] <= target) {
            ds.push_back(candidates[index]);
            fn(answer, ds, candidates, target - candidates[index], index);
            ds.pop_back();
        }
        fn(answer, ds, candidates, target, index + 1);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> ds;
        fn(answer, ds, candidates, target, 0);
        return answer;
    }
};