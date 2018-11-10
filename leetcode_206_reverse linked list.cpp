// 3个指针实现
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode *a, *b, *c;
        a = head;
        b = head->next;
        c = b->next;
        a->next = NULL;
        while(1){
            b->next = a;
            a = b;
            if(c==NULL) return a;
            b = c;
            c = c->next;
        };
        
    }
};

// 递归实现
class Solution{
public:
	ListNode* reverseList(ListNode* head){
		if(!head || !(head->next)){
			return head;
		}
		ListNode *node = reverseList(head->next);
		head ->next ->next = head;
		head->next = NULL;
		return node;
	}
};


