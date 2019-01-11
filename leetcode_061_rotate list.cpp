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
    ListNode *recursive(ListNode *head, int k){
        if(k==0 || head==NULL || head->next==NULL) return head;
        ListNode *p = head, *q = head->next;
        while(q->next != NULL){
            q = q->next;
            p = p->next;
        }
        p->next = NULL;
        q->next = head;
        head = q;
        return recursive(head, k-1);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode *p=head;
        while(p!=NULL){
            p = p->next;
            len++;
        }
        if(len==0) return head;
        k = k%len;
        return recursive(head, k);
    }
};