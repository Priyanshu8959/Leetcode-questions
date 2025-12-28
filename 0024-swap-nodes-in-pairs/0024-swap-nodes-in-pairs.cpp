class Solution {
public:
    // same function, bas return type fix
    ListNode* reverse(ListNode* head, int times) {
        ListNode* current = head;
        ListNode* prev = NULL;

        while (times-- && current) {
            ListNode* nex = current->next;
            current->next = prev;
            prev = current;
            current = nex;
        }
        return prev;    
    }

    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* left = head;
        ListNode* right = NULL;
        ListNode* res = NULL;
        ListNode* prevleft = NULL;
        int size = 2;

        while (left != NULL) {

            right = left;   

            for (int i = 0; i < size - 1; i++) {
                if (right == NULL) {
                    break;
                }
                right = right->next;
            }

            if (right != NULL) {
                ListNode* nextleft = right->next;

                 ListNode* newHead = reverse(left, size);

                if (prevleft != NULL)
                    prevleft->next = newHead;

                if (res == NULL) {
                    res = newHead;
                }

                 left->next = nextleft;

                prevleft = left;
                left = nextleft;
            }
            else {
                if (prevleft) {
                    prevleft->next = left;
                }
                if (res == NULL) {
                    res = left;
                }
                break;   
            }
        }
        return res;
    }
};
