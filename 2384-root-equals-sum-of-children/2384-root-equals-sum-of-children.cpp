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
    bool checkTree(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        if(root==NULL) return true;
        int childSum = 0;
        if(root->left!=NULL){
            childSum+=root->left->val;
        }
        if(root->right!=NULL){
            childSum+=root->right->val;
        }
        return(childSum==root->val)&& checkTree(root->left)&& checkTree(root->left) ;
        
    }
};