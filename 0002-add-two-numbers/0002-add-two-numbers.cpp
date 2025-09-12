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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int carry = 0;
      ListNode*dummyNode= new ListNode(0) ;
      ListNode* current = dummyNode;
      ListNode* temp1 = l1;
      ListNode* temp2 = l2;
      while(temp1!=NULL || temp2!=NULL){
        int  sum = carry;
        if(temp1!=NULL){
            sum+=temp1->val;
             temp1= temp1->next;
        }
        if(temp2!=NULL){
            sum+=temp2->val;
              temp2= temp2->next;
        }
        ListNode* newNode = new ListNode(sum%10);
        current ->next = newNode;
        carry= sum/10;
        current = current->next;
                 
      }
      if(carry>0){
        ListNode* newnode= new ListNode ( carry);
        current->next = newnode;
      }
      return dummyNode->next;
    }
};