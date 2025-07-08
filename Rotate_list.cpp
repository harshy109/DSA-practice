class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while( temp != NULL){
            len++;
            temp = temp -> next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;

        int L = getLength(head);
        int breakP = k%L;
        if(L== 1 || breakP == 0) return head;

        int positionToBreak = L - breakP -1;
        ListNode* temp = head;

        for(int i = 0; i<positionToBreak ; i++){
            temp = temp->next;
            // nextN = nextN->next;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;

        ListNode* secondTail= newHead;
        
        while(secondTail->next != NULL){ //traverse till last of new list
            secondTail = secondTail->next;
        }
        secondTail->next = head; //connect its tail with head of first
        
        return newHead;
    }
};
