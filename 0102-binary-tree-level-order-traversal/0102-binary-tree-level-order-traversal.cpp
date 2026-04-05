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
    vector<vector<int>> levelOrder(TreeNode* root) {
              vector<vector<int>>ans;

        if(root==NULL)return ans;
      queue<TreeNode*> que ;
     que.push(root);
     while(!que.empty()){
int n = que.size();
      vector<int>level;
      while(n--){
        TreeNode* current = que.front();
        que.pop();
        level.push_back(current->val);
        if(current->left!=NULL){
            que.push(current->left);
        }
        if(current->right!=NULL){
          que.push(current->right);
        }
         
      }
      ans.push_back(level);
        
     }
        return ans; 
    }
};