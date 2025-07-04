class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        //jab tak fast null na ho jaye
        while(fast!=NULL){
            fast=fast->next;

            //check kaarlo kahi last pe to nhi poch gye
            if(fast == NULL){
                return slow;
            }
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};
