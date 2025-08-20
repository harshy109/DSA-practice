// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool checkCompleteness(Node* root){
        queue<Node*> q;
        q.push(root);

        bool nullFound = false;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();

            if(front == NULL){
                nullFound = true;
            }
            else{
                if(nullFound){
                    return false;
                }
                else{
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        return true;
    }
    bool checkMaxProperty(Node* root){
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        
        bool leftAns = checkMaxProperty(root->left);
        bool rightAns = checkMaxProperty(root->right);
        
        bool option1 = true; //here true not false
        bool option2 = true;
        if(root->left && root->data < root->left->data){
            option1 = false;
        }
        //if right doesnt exist in that case it will be false as this condition it didnt execute
        if(root->right && root->data < root->right->data){
            option2 = false;
        }
        
        bool currAns = option1 && option2;
        
        if(leftAns && rightAns && currAns) return true;
        return false;
    }
    bool isHeap(Node* tree) {
        bool completeness = checkCompleteness(tree);
        bool maxProperty = checkMaxProperty(tree);
        
        if(completeness && maxProperty) return true;
        return false;
        
    }
};
