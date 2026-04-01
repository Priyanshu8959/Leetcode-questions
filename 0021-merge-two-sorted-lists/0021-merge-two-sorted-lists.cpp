class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val <= temp2->val) {
                tail->next = temp1;
                temp1 = temp1->next;
            } else {
                tail->next = temp2;
                temp2 = temp2->next;
            }
            tail = tail->next;
        }

        tail->next = temp1 ? temp1 : temp2;

        return dummy.next;
    }
};