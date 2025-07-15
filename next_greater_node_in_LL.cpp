
class Solution {
public:
    void solve(ListNode* &head,stack<int> &s,vector<int> &ans){
        //base case'
        if(head->next==NULL){
            s.push(head->val);
            ans.push_back(0);
            return;
        }
        //rest of cases
        solve(head->next, s, ans);
        // if(s.empty()) ans.push_back(0);
        //else{
            while(!s.empty() && s.top() <= head->val){
                s.pop();
            }
            if(s.empty()) ans.push_back(0);
            else ans.push_back(s.top());
            s.push(head->val);
        //}
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        solve(head, s, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
