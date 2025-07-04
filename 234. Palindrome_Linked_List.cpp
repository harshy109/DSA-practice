class Solution {
public:
    ListNode* findMiddle(ListNode* &slow, ListNode* &fast, ListNode* &midKaPrev){
        while(fast != NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                midKaPrev = slow;
                slow = slow->next;
            }  
        }
        return slow;
    }
    ListNode* reverseLL(ListNode* &prev, ListNode* &curr){
        if(curr == NULL){
            return prev;
        }

        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        return reverseLL(prev, curr);
    } 
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL){
            return true;
        }
        //find middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* midKaPrev=NULL;
        ListNode* mid = findMiddle(slow, fast, midKaPrev);

        //break
        midKaPrev->next = NULL;

        ListNode* tempHead1 = head;

        ListNode* prev = NULL;
        ListNode* curr = mid;

        ListNode* tempHead2 = reverseLL(prev, curr);

        while(tempHead1 != NULL){
            if(tempHead1->val != tempHead2->val){
                return false;
            }
            else{
                tempHead1 = tempHead1->next;
                tempHead2 = tempHead2->next;
            }
        }
        return true;

        //break
        //reverse
        //compare
        //return ans
    }
};
