class Solution {
public:
    void fn(vector<vector<int>>& answer, vector<int>& ds,
            vector<int>& candidates, int target, int index) {

        if (target == 0) {
            answer.push_back(ds);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
             if (i > index && candidates[i] == candidates[i - 1])
                continue;

             if (candidates[i] > target)
                break;

            ds.push_back(candidates[i]);
            fn(answer, ds, candidates, target - candidates[i], i + 1);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> ds;
        fn(answer, ds, candidates, target, 0);
        return answer;
    }
};
