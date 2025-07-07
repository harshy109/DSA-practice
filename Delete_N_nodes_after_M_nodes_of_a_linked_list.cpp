class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
//nayi approach
        Node* prev = head;
        while(prev!=NULL){
            for(int i = 0; i<m-1 && prev; i++){
                    prev = prev->next;
            }
            if(prev == NULL) break;
                
            Node* curr = prev->next;
            for(int j = 0 ; j<n && curr; j++){
                curr = curr->next;
            }
            prev->next = curr;
            prev = curr;
        }
        return head;
    }
};
