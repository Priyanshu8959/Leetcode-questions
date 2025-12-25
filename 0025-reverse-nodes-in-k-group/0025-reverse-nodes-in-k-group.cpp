class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1) return head;

        // Count nodes
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        int groups = count / k;

        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* before = NULL;
        ListNode* newHead = NULL;

        while (groups--) {

            ListNode* tail = current;   // will become tail after reverse
            prev = NULL;

            int kk = k;  // temp k
            while (kk--) {
                ListNode* after = current->next;
                current->next = prev;
                prev = current;
                current = after;
            }

            // First group
            if (newHead==NULL)
                newHead = prev;
            else
                before->next = prev;

            before = tail;
        }

        // Connect remaining nodes
        before->next = current;

        return newHead;
    }
};
