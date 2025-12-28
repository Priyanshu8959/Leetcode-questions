/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 ListNode* reverse(ListNode* head, int times) {
        ListNode* current = head;
        ListNode* prev = NULL;

        while (times--  ) {
            ListNode* nex = current->next;
            current->next = prev;
            prev = current;
            current = nex;
        }
        return prev;   
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* left = head;
        ListNode* right = NULL;
        ListNode* res = NULL;
        ListNode* prevleft = NULL;
        int size = k;

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