class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right) return head;

        ListNode* helper = head;
        ListNode* before = NULL;
        ListNode* prev = NULL;

        int position = 1;
        int times = right - left + 1;

         
        while (position < left) {
            before = helper;
            helper = helper->next;
            position++;
        }

        ListNode* current = helper;

     
        while (times--) {
            ListNode* after = current->next;
            current->next = prev;
            prev = current;
            current = after;
        }

    
        if (before != NULL)
            before->next = prev;
        else
            head = prev;    

        helper->next = current;

        return head;
    }
};
