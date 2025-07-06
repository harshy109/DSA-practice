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
    ListNode* findLoop(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(slow==fast){
                ///jaha fast and slow meet kar rhe hain
                //wo point hasCycle point return kardo
                return fast;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = findLoop(head);
        //agar loop hai hi nhi -> fast - NULL
        if(fast == NULL) return NULL;
        ListNode* slow = head;
        while(slow != fast){
            slow = slow-> next;
            fast = fast-> next;
        }
        return slow;

        // unordered_map<ListNode*, bool> m;
        // ListNode* temp = head;
        // while(temp!=NULL){
        //     if(m[temp]==true){
        //         return temp;
        //     }
        //     else{
        //         m[temp]=true;
        //     }
        //     temp = temp->next;
        // }
        // return NULL;

 
    }
};
