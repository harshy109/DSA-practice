class Solution {
public:

    ListNode* reverseLL(ListNode* &prev, ListNode* &curr){
        //base case
        if(curr == NULL){
            return prev;
        }

        //create forward
        ListNode* forward = curr->next;
        //curr ko piche ki disha me ghuma diya
        curr->next = prev;
        //pointer aage bdha diye
        prev = curr;
        curr = forward;

        return reverseLL(prev, curr);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        //ListNode* newNode = reverseLL(prev, curr);

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr= forward;
        }
        return prev;

    }
};
