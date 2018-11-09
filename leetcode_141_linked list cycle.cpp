class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        if(head==NULL || head->next==NULL) return false;
        slow = head;
        fast = head->next->next;
        while(slow!=fast){
            if(fast==NULL || fast->next==NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
            
        }
        return true;
    }
};