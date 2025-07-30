/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node* node,int &sum, queue<int> &q){
        if(node == NULL){
            return 0;
        }
        
        //its a leaf node
        if(node->left == NULL && node->right == NULL){
            q.push(0);
            return node->data;
        }
        
        int left = solve(node->left,sum, q); //8
        int right = solve(node->right,sum,q); //-4
        sum = left + right; //0+8-4 = 4
        q.push(sum); //4
        return sum + node->data; 
    }
    void postOrder(Node* &node, queue<int> &q){
        if(node==NULL){
            return;
        }
        
        if(node->left == NULL && node->right == NULL){
            node->data = q.front();
            q.pop();
            return;
        }
        
        postOrder(node->left,q);
        postOrder(node->right,q);
        node->data = q.front();
        q.pop();
        
    }
    void toSumTree(Node *node) {
        queue<int> q;
        int sum = 0;
        solve(node,sum, q);
        
        //postorder traversal
        postOrder(node, q);
    }
};
