//思路一 递归 【20ms】
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
    // 从已经排序的链表中去掉重复元素
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *cur = head;
        ListNode *move = cur->next;
        while(true){
            if(move==nullptr){
                cur->next = move;
                return head;
            }
            else if(move->val == cur->val) move=move->next;
            else {
                cur->next =  deleteDuplicates(move);
                return head;
            }
        }
    }
};

//思路二 非递归方法 找到第一个和当前指针不相同的数 再进行指针调整【20ms】
class Solution {
public:
    //非递归方法实现 删除链表中重复的元素
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *cur = head;
        ListNode *move = head->next;
        while(move!=nullptr){
            if(move->val != cur->val){
                cur->next = move;
                cur = move;
                move = move->next;
            }
            else move=move->next;
            if(move==nullptr){
                cur->next = move;
                return head;
            }
        }
        return head;
    }
};

// 思路三 非递归方法 每次找到一个和当前指针相同的数就删除【12ms 100%】
class Solution {
public:
    // 删除链表中重复的结点，每次找到一个和当前结点一样的结点就删除
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *cur = head, *move = head->next;
        while(move!=nullptr){
            if(move->val == cur->val){
                move = move->next;
                cur->next = move;
            }
            else{
                cur = cur->next;
                move = move->next;
            }
        }
        return head;
    }
};