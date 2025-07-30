/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    void solve(Node* &root, queue<int> &q, queue<int> &leftQ, vector<int> &ans){
        if(root == NULL){
            while(!q.empty()){
                ans.push_back(q.front());
                q.pop();
            }
        }
        
        
    }
    vector<int> diagonal(Node *root) {
        queue<Node*> q;
        queue<Node*> leftQ;
        vector<int> ans;
        solve(root, q, leftQ, ans);
        
        q.push(root);
        int level = 0;
        
        while(!q.empty()){
            Node* front = q.front();
            ans.push_back(q.front()->data);
            q.pop();
            if(front == NULL){
                // while(!q.empty()){
                //     ans.push_back(q.front()->data);
                //     q.pop();
                // }
                if(level != 0){
                    while(!leftQ.empty()){
                        ans.push_back(leftQ.front()->data);
                        leftQ.pop();
                    }
                }
                q.pop();
                q.push(ans.front()->left);
                level++;
            }
            else{
                if(node->right){
                    q.push(node->right);
                }
                else{
                    q.push(NULL);
                }
                
                if(node->left){
                    leftQ.push(node->left);
                }
            }
        }
        
        return ans;
    }
};
