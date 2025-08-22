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

class comp{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    } 
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* headMain = NULL;
        ListNode* tail = NULL;
        priority_queue<ListNode* , vector<ListNode*>, comp > q;
        for(int i = 0; i<lists.size(); i++){
            ListNode* head = lists[i];
            if(head){
                q.push(head);
            }
        }
        while(!q.empty()){
            ListNode* temp = q.top();
            q.pop();
            if(headMain == NULL){
                headMain = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
            if(tail->next != NULL){
                q.push(tail->next);
            }
        }
        return headMain;
    }
};
