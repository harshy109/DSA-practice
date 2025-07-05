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
    void removeNodeAtPos(int position, ListNode* &head){
            ListNode* temp = head;
            for(int i = 0; i<position-2; i++){
                temp = temp->next;
            }
            ListNode* curr = temp->next;
            temp->next = curr->next;
            curr->next = NULL;
            delete curr;

        //}
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode* prev= head;
        ListNode* temp = prev->next;

        while(temp != NULL){
            if(temp->val == prev->val){
                //remove karenge
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
            else{
                //temp = temp->next ;
                prev = prev->next ;
            }
            temp =prev->next;
        }
        // unordered_map <int, int> m;
        // ListNode* temp  = head;
        // int pos = 1;
        // while(temp != NULL){
        //     //int val = ;
        //     if(m[temp->val]>1){
        //         removeNodeAtPos(pos, head);

        //     }
        //     else{
        //         m[temp->val]++;
                
        //     }
        //     temp=temp->next;
        //     pos++;
        // }
        return head;
    }
};
