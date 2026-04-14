class Solution {
public:
    vector<vector<int>> result;  
    vector<int> current;        

    void dfs(TreeNode* root, int rem) {

         if (root == nullptr) return;

        // ✅ STEP 1: Make choice — add to shared path
        current.push_back(root->val);
        rem = rem - root->val;

        // ✅ STEP 2: Check — leaf node AND sum matches
        bool isLeaf = !root->left && !root->right;
        if (isLeaf && rem == 0) {
            result.push_back(current); // save a COPY of current path
        }

        // ✅ STEP 3: Explore children
        dfs(root->left,  rem);
        dfs(root->right, rem);

        // ✅ STEP 4: Undo choice — backtrack
        current.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return result;
    }
};