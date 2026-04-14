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
int dfs(TreeNode* root, int num){
if(root==NULL) return 0; // edge case
int new_number = 10*num+root->val;
if(root->left==NULL && root->right==NULL){ //edge  case 
    return new_number ;
}
int l = dfs(root->left,new_number);
int r = dfs(root->right,new_number);
return l+r;

}
    int sumNumbers(TreeNode* root) {
      int num = 0;
      return dfs(root,num);  
    }
};