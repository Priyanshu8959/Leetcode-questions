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
    ListNode* sortList(ListNode* head) {
        vector<int>nodes;
        ListNode* temp = head;
        while(temp!=NULL){
            nodes.push_back(temp->val);
            temp=temp->next;
        }
        sort(nodes.begin(),nodes.end());
        ListNode* dummy = new ListNode(0);
        ListNode* helper = dummy;
        int i=0;int n = nodes.size();
        while(n--){
            helper->next= new ListNode(nodes[i]);
            i++;
            helper = helper ->next; 
        }
        return dummy->next;
    }
};