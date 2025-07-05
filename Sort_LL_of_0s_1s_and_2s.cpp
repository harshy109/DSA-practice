/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    void insertAtTail(Node* &toMove, Node* &head, Node* &tail){
        if(head == NULL){
            head = toMove;
            tail = toMove;
        }
        else{
            tail->next = toMove;
            tail = tail->next;
        }
    }
    Node* segregate(Node* head) {
        Node* zeroHead = NULL;
        Node* zeroTail = NULL;
        
        Node* oneHead = NULL;
        Node* oneTail = NULL;
        
        Node* twoHead=  NULL;
        Node* twoTail = NULL;
        
        Node* temp = head;
        
        
        while(temp != NULL){
            //toMove bnaya
            //isolate kiya
            Node* toMove = temp;
            temp=temp->next;
            toMove->next = NULL;
            if(toMove->data == 0){
                insertAtTail(toMove, zeroHead, zeroTail);
            }
            if(toMove->data == 1){
                // oneTail->next = temp;
                // temp->next = NULL;
                // head = forward;
                insertAtTail(toMove, oneHead, oneTail);
            }
            if(toMove->data == 2){
                insertAtTail(toMove, twoHead, twoTail);
            }
        }
    
        if(zeroHead != NULL){
            //zL is non-empty
            if(oneHead != NULL){
                zeroTail->next = oneHead;
                oneTail->next = twoHead;
            }
            else{
                zeroTail->next = twoHead;
            }
        }
        else{
            //zL is empty
            if(oneHead != NULL){
                oneTail->next = twoHead;
                return oneHead;
            }
            else{
                return twoHead;
            }
        }
        
        return zeroHead;
        
    }
};
