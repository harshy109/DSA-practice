class Solution {
public:
    int getLength(ListNode* &head){
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            temp=temp->next;
            len++;
        }
        return len;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        int len = getLength(head);
        if(len < k){
            return head;
        }

        //ek case hum solve krenge baki recursion karega
        //reverse karenge hum
        ListNode* prev= NULL;
        ListNode* curr = head;
        int pos = 0;
        while(pos<k){
            ListNode* forward = curr->next ;
            curr->next = prev;
            prev= curr;
            curr= forward;
            pos++;
        }     
        if(curr != NULL){
            ListNode* recursionKaHead = reverseKGroup(curr, k);
            head->next = recursionKaHead;
        }
        

        return prev;
    }
};
