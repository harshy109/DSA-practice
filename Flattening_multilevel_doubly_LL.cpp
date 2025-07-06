/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
    Node* solve(Node* head){
        Node* it = head;
        Node* tail = it;

        while(it!=NULL){
            if(it->child){
                Node* temp = it->next;
                Node* childTail = solve(it->child);
                //flattening
                //new connection 
                it->next = it->child;
                it->next->prev = it;
                //new tail connects with temp
                childTail->next = temp;
                if(temp!=NULL) temp->prev = childTail;
                //remove child connection
                it->child = NULL;
            }
            tail = it;
            //it->next = 7
            it = it->next;
        }
        return tail;
    }
class Solution {
public:
    Node* flatten(Node* head) {
        //solve thru recursion
        if(!head) return NULL;
        solve(head);
        return head;
    }
};
