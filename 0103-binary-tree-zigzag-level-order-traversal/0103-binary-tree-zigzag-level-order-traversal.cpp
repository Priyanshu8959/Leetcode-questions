/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool lefttoright = true;
        if(root==NULL)return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> result;
        while (que.size() != 0) {
            int n = que.size();
            vector<int> level(n);

             
            for (int i = 0; i < n; i++) {
                TreeNode* current = que.front();
            que.pop();
                int index;
                if (lefttoright == true) {
                    index = i;
                } else {
                    index = n - i - 1;
                }
                level[index] = current->val;
                if (current->left) {
                    que.push(current->left);
                }
                if (current->right) {
                    que.push(current->right);
                }
            }
            result.push_back(level);
            lefttoright = !lefttoright;
        }
        return result;
    }
};