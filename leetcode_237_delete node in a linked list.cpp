class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node->next==NULL){
            free(node);
            return;
        } 
        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};