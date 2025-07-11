#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void solve(stack<int> &s,vector<int> &v ,vector<int> &ans){
    for(int i = 0; i<v.size(); i++){
        int element = v[i];
        //wo khali hoga hi nhi
        //-1 jo hai
        while(s.top()>element){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(element);
    }
    
}

int main(){
    vector<int> v = {2,3,4,5,1};
    stack<int> s;
    s.push(-1);
    vector<int> ans;

    solve(s, v, ans);

    for(auto it:ans){
        cout<<it<<" ";
    }


    return 0;
}
