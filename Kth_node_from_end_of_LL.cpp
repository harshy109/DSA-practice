class Solution {
  public:
    int getLength(Node *head){
        Node* temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
    int getKthFromLast(Node *head, int k) {
        // Your code here
        int len = getLength(head);
        if(k>len) return -1;
        int toMove = len - k;
        
        Node* temp = head;
        for(int i = 0; i<toMove; i++){
            temp = temp->next;
        }
        return temp->data;
    }
};
