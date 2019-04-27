// 合并2个本身就有序的链表
// 思路是，首相调整两个链表 使得l1的第一个元素 <= l2的第一个元素 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 合并两个有序的链表
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode *head = l1;
        if(l2->val < l1->val){ // 保证初始时候l1所指的数更小
            l1= l2;
            l2 = head;
            head = l1;
        }
        while(l1->next!=nullptr && l2!=nullptr){
            if(l2->val>=l1->val && l2->val <= l1->next->val){// 当前l2刚好可以插在l1和l1->next之间
                ListNode *t = l1->next;
                l1->next = l2;
                l2 = l2->next;
                l1->next->next = t;
            }
            else{
                l1= l1->next;
            }
        }
        if(l1->next == nullptr) l1->next = l2;
        return head;
        
    }
};

// 递归实现

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode *head;
        if(l1->val < l2->val){
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
            return head;
        }
        else{
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
            return head;
        }
        
    }
};