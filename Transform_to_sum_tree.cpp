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
    //used queue to store sum
    int solve(Node* &node,int &sum, queue<int> &q){
        if(node == NULL){
            return 0;
        }
        
        //its a leaf node
        if(node->left == NULL && node->right == NULL){
            q.push(0);
            int val = node->data;
            node->data = 0;
            return val;
        }
        
        int left = solve(node->left,sum, q); //8
        int right = solve(node->right,sum,q); //-4
        sum = left + right; //0+8-4 = 4
        q.push(sum); //4
        int val =  node->data;
        node->data = left+right;
        return sum + val; 
    }
    //new approach without queue (additional data structure)
    int solve1(Node* &node,int &sum){
        if(node == NULL){
            return 0;
        }
        
        //its a leaf node
        if(node->left == NULL && node->right == NULL){
            int val = node->data;
            node->data = 0;
            return val;
        }
        
        int left = solve1(node->left,sum); //8
        int right = solve1(node->right,sum); //-4
        sum = left + right; //8-4 = 4
        int val =  node->data;
        node->data = left+right;
        return sum + val; 
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
        //store sum of subtrees in queue
        // solve(node,sum, q);
        solve1(node,sum);
        
        //postorder traversal
        // postOrder(node, q);
    }
};
