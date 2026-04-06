class Solution {
public:
    // checks if two trees are exactly identical
    bool helper(TreeNode* r1, TreeNode* r2) {
        if (r1 == NULL && r2 == NULL) return true;
        if (r1 == NULL || r2 == NULL) return false;
        if (r1->val != r2->val) return false;

        bool f1 = helper(r1->left, r2->left);
        bool f2 = helper(r1->right, r2->right);
        return f1 && f2;
    }

     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;
        if (helper(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};