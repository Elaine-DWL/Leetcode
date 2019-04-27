// 借助优先队列来实现
class Solution {
public:
    struct cmp{
        bool operator()(ListNode *node1, ListNode *node2){
            return node1->val > node2->val;// 最小值优先
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return nullptr;
        if(n==1) return lists[0];
        ListNode *head = nullptr, *cur = nullptr, *t;
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        for(int i=0; i<n; i++){
            if(lists[i]!=nullptr){
                q.push(lists[i]);
            }
        }
        while(!q.empty()){
            // 取出当前优先队列中的第一个
            t = q.top();
            q.pop();
            if(head==nullptr){
                head = t;
                cur = t;
            }
            else{
                cur->next = t;
                cur = t;
            }
            if(t->next ！=nullptr) q.push(t->next);
        }
        return head;
        
    }
};