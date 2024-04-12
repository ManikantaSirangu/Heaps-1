// t-c: Nlog(k);
// s-c: k
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct comparator{
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparator> pq;
        ListNode* head = new ListNode();
        ListNode* tail = head;
        for(ListNode* node: lists)
        {
            if(node != NULL)
                pq.push(node);
        }
        while(!pq.empty())
        {
            ListNode* temp = pq.top();
            pq.pop();
            if(temp->next != NULL)
                pq.push(temp->next);
            tail->next = temp;
            tail = temp; 
        }
        return head->next;
    
    }
};
