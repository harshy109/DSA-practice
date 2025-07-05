
class Solution {
  public:
    void insertAtTail(int value, Node* &head, Node* &tail){
            Node* newNode =new  Node(value);
            tail->next = newNode;
            tail = newNode;
    }
    Node* reverseLL(Node* &prev, Node* &curr){
        if(curr == NULL){
            return prev;
        }
        Node* forward = curr->next;
        curr->next = prev;
        prev=curr;
        curr=forward;
        return reverseLL(prev, curr);
    }
    Node* addOne(Node* head) {
        // Your Code here
        Node* prev = NULL;
        Node* curr = head; 
        Node* newHead = reverseLL(prev, curr);
        Node* temp = newHead;
        int sum = 0, carry = 0;
        
        if(temp->data < 9){
            temp->data +=1;
        }
        else{
            sum = (temp->data)+1+carry;
            carry = sum/10;
            temp->data = sum%10;
            while(carry!=0 && temp->next != NULL){
                temp = temp->next;
                sum = (temp->data)+carry;
                carry = sum/10;
                temp->data = sum%10;
            }
            if(temp->next == NULL){
                insertAtTail(carry, newHead, temp);
            }
        }
        
        //reverse again
        prev = NULL;
        curr = newHead;
        
        return reverseLL(prev, curr);
        
        // return head of list after adding one
        //return head;
    }
};
