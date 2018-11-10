class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode *slow=head, *fast=head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next==NULL) return slow;
        return slow->next;
    }
};