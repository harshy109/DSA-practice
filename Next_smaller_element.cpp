#include<stack>
void solve(stack<int> &s, int target, vector<int> &ans, int position){
    if(s.empty()){
        ans[position] = -1;
        return;
    }
    if(s.top()<target){
        ans[position] = s.top();
        return;
    }
    
    int topE = s.top();
    s.pop();
    solve(s,target,ans, position);
    s.push(topE);
}

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    //solved with array/vector - O(n)
    // vector<int> ans(n,-1);
    // for(int i = 0; i<arr.size(); i++){
    //     int target = arr[i];
    //     for(int j = i+1; j<arr.size(); j++){
    //         if(arr[j]<target){
    //             ans[i]=arr[j];
    //             break;
    //         }
    //         else if(arr[j] > target){
    //             continue;
    //         }
    //         else if(j==arr.size()-1 && arr[j] > target){
    //             ans[i] = -1;
    //         }
    //     }
    // }
    stack<int> s;
    //pushed in stack
    for(int i = arr.size()-1; i>=0; i--){
        s.push(arr[i]);
    }
    vector<int> ans(n,-1);
    int position = 0;
    while(!s.empty()){
        int target = s.top();
        s.pop();
        solve(s,target,ans, position);
        position++;
        
    }
    return ans;
}
