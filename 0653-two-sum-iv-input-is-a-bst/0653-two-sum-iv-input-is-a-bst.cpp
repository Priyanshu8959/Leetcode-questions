class Solution {
public:
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    int next() {
        TreeNode* temp = s1.top();
        s1.pop();
        TreeNode* node = temp->right;
        while (node != NULL) {
            s1.push(node);
            node = node->left;
        }
        return temp->val;
    }

    int before() {
        TreeNode* temp = s2.top();
        s2.pop();
        TreeNode* node = temp->left;
        while (node != NULL) {
            s2.push(node);
            node = node->right;
        }
        return temp->val;
    }

    bool findTarget(TreeNode* root, int k) {
        TreeNode* t = root;
        while (t) {
            s1.push(t);
            t = t->left;
        }
        t = root;
        while (t) {
            s2.push(t);
            t = t->right;
        }
        int s = next(), e = before();
        while (s < e) {
            if (s + e == k)
                return true;
            else if (s + e < k)
                s = next();
            else
                e = before();
        }
        return false;
    }
};