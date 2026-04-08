class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;

        if(p->val > q->val) swap(p, q);

        while(root){
            if(root->val < p->val){
                root = root->right;
            }
            else if(root->val > q->val){
                root = root->left;
            }
            else{
                return root; // THIS IS LCA
            }
        }
        return NULL;
    }
};