
class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code here
        Node* temp2 = head2;
        Node* temp1 = head1;
        
        Node* finalAns = new Node(-1);
        Node* ans = finalAns;
        
        unordered_map<int, int> mp;
        while(temp2 != NULL){
            mp[temp2->data]++;
            temp2 = temp2->next;
        }
        while(temp1 != NULL){
            mp[temp1->data]++;
            temp1 = temp1->next;
        }
        Node* temp11 = head1;
        while(temp11!=NULL){
            if(mp[temp11->data]==2){
                ans->next = new Node(temp11->data);
                ans=ans->next;
                temp11 = temp11->next;
            }
            else{
                temp11 = temp11->next;
            }
        }
        return finalAns->next;
    }
};
