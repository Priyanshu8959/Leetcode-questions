class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
         while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->val == val) {
                ListNode* del = temp->next;
                temp->next = temp->next->next; 
                delete del;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};
