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
TreeNode* ans = NULL;
int LCA(TreeNode* root, TreeNode* p, TreeNode* q){
if(root==NULL) return 0;
         
        int total = 0;
        int r1 = LCA(root->left ,p,q);
        int r2 = LCA(root->right,p,q);
        int self = 0;
        if(root==p || root==q){
            self = 1;
        }
        total = r1 + self + r2;
        if(ans==NULL && total==2){
            ans = root;
        }
        return total;
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           LCA(root,p,q);
         return ans;
    }
};