/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 */

// This function should return head to the DLL
class Solution {
  public:
    void solve(Node* root, Node* &head){
        if(root ==  NULL){
            return;
        }
        
        solve(root->right, head);
        root->right = head;
        if(head!=NULL){
            head->left = root;
        }
        head = root;
        solve(root->left, head);
    }
    Node* bToDLL(Node* root) {
        // code here
        Node* head = NULL;
        solve(root, head);
        return head;
    }
};
