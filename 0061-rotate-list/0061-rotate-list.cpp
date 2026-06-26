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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head ==NULL || head->next == NULL){
            return head;
        }
        if (k == 0){
            return head;
        }
        int length = 1;
        ListNode* temp = head;
        while(temp !=NULL && temp->next != NULL){
            temp = temp->next;
            length ++;
        }

        temp->next = head; // now it has become the circular ll
        ListNode* new_tail = head;
        k = k % length;
         
         
        int steps = length - k - 1;
        while(steps--){
            new_tail = new_tail->next;
        }

        //new head 
         ListNode* new_head = new_tail->next;
         new_tail->next = NULL;
         return new_head;


    }
};