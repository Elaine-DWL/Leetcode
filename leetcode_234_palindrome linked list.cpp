// 快慢指针  反转 比较
class Solution {
public:
    ListNode *reverse(ListNode *head){
        if(!head || !(head->next)) return head;
        ListNode *node = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast;
        slow = head;
        fast = head;
        if(!fast || !(fast->next)) return true;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *node=NULL, *p;
        p = slow->next;
        slow->next = NULL;
         node = reverse(p);
        // if(node==NULL) cout<<"空"<<endl;
        while(node&&head){
            if(head->val!=node->val) return false;
            head = head->next;
            node = node->next;
        }
        return true;
    }
};