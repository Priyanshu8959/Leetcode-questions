/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     void findNodes(TreeNode *root, int dis, vector<int> &ans) {
        if (!root) return;
        if (dis == 0) {
            ans.push_back(root->val);
            return;
        }
        findNodes(root->left, dis - 1, ans);
        findNodes(root->right, dis - 1, ans);
    }

     int kDistanceRecur(TreeNode *root, TreeNode *target, int k, vector<int> &ans) {
        if (!root) return -1;

         if (root == target) {
            findNodes(root, k, ans);
            return 1;
        }

        int left = kDistanceRecur(root->left, target, k, ans);
        if (left != -1) {
            if (k - left == 0)
                ans.push_back(root->val);
            else
                findNodes(root->right, k - left - 1, ans);
            return left + 1;
        }

        int right = kDistanceRecur(root->right, target, k, ans);
        if (right != -1) {
            if (k - right == 0)
                ans.push_back(root->val);
            else
                findNodes(root->left, k - right - 1, ans);
            return right + 1;
        }

        return -1;
    }

     
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        vector<int> ans;
        kDistanceRecur(root, target, k, ans);
        return ans;  
    }
};
