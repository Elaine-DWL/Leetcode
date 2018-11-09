class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre, *cur;
        while(head && head->val == val) head = head->next;
        pre = head;
        if(pre==NULL) return NULL;
        cur = head->next;
        while(cur){
            if(cur->val == val){
                pre->next = cur->next;
                free(cur);
                cur = pre->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return head;    
    }
};