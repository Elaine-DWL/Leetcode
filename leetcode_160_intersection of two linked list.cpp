// 思路一
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        int len1 = 0, len2 = 0;
        ListNode *p1 = headA, *p2=headB;
        while(p1){
            p1=p1->next;
            len1++;
        }
        while(p2){
            p2=p2->next;
            len2++;
        }
        p1 = headA;
        p2 = headB;
        if(len1<len2){
            for(int i=0; i<len2-len1; i++){
                p2 = p2->next;
            }
        }
        else if(len1>len2){
            for(int i=0; i<len1-len2; i++){
                p1 = p1->next;
            }
        }
        if(p1==p2) return p1;
        while(p1!=p2){
            p1 = p1->next;
            p2 = p2->next;
            if(p1==p2) return p1;
        }
        return NULL;
        
    }
};





// 思路三
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur1 = headA, *cur2 = headB;
    while(cur1 != cur2){
        cur1 = cur1?cur1->next:headB;
        cur2 = cur2?cur2->next:headA;
    }
    return cur1;
}
