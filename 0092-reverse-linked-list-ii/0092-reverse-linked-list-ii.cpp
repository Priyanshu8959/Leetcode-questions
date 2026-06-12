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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         ListNode* helper = head;
          ListNode*  before = NULL;
          int times = right-left+1;
          if(left==right) return head;

            int pos = 1;
           while(pos<left){
            before = helper;
            helper = helper ->next;
            pos++;
           }
          
            ListNode* current= helper;

            //reversal 
             ListNode*  pre = NULL;
            while(times--){
                 ListNode* ahead = current->next;
                 current->next = pre;
                 pre = current;
                 current = ahead;
            }

            //connection of node 
            if(left == 1){
                head = pre ;
            }
            else{
             before ->next = pre;
            }
            helper ->next = current;
            return head;
    }
};