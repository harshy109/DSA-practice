/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<Node*> q;
        queue<Node*> leftQ;
        
        
        q.push(root);
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front == NULL){
                if(!leftQ.empty()){
                    q.push(leftQ.front());
                    leftQ.pop();
                }
            }
            else{
                ans.push_back(front->data);
                if(front->right){
                    q.push(front->right);
                }
                else{
                    q.push(NULL);
                }
                
                if(front->left){
                    leftQ.push(front->left);
                }
            }
        }
        
        return ans;
    }
};
