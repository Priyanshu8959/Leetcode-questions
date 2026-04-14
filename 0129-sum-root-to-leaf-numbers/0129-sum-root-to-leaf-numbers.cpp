/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int totalSum = 0;
    string current = "";  

    void helper(TreeNode* root) {

        if (root == NULL) return;

          current += to_string(root->val);

        if (!root->left && !root->right) {
            totalSum += stoi(current);  
        }

        // Explore karo
        helper(root->left);
        helper(root->right);

         current.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        helper(root);
        return totalSum;
    }
};