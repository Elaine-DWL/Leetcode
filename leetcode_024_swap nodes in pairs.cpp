/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        // if(head->next->next==NULL){
        //     ListNode *t = head->next;
        //     head->next = NULL;
        //     t->next = head;
        //     head = t;
        //     return head;    
        // }
        ListNode *a=head, *b=head->next, *ok=head;
        while(b!=NULL){
            if(ok!=head) ok->next = b;
            else{
                head = b;
            }
            a->next = b->next;
            ok = a;
            b->next = a;
            if(a->next==NULL) return head;
            b = a->next->next;
            a = a->next;
        }
        return head;
    }
};

// 递归代码
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *a=head, *b=head->next;
        head = b;
        a->next = b->next;
        b->next = a;
        a->next = swapPairs(a->next);
        return head;
            
    }
};