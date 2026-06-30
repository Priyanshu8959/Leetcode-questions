class Solution {
public:
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }

    Node* dfs(Node* node) {

        Node* curr = node;
        Node* last = nullptr;

        while (curr != nullptr) {

            Node* next = curr->next;

            if (curr->child) {

                Node* childLast = dfs(curr->child);

                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;

                if (next) {
                    childLast->next = next;
                    next->prev = childLast;
                }

                last = childLast;
            }
            else {
                last = curr;
            }

            curr = next;
        }

        return last;
    }
};