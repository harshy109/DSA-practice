class Solution {
  public:
    string FirstNonRepeating(string &s) {
        unordered_map<char, int> mp;
        queue<char> q;
        string ans = "";
        
        for(char ch : s){
            mp[ch]++;
            q.push(ch);
            
            while(!q.empty()){
                if(mp[q.front()]==1){
                    ans.push_back(q.front());
                    break;
                }
                else {
                    q.pop();
                }
            }
            
            if(q.empty()){
                ans+='#';
            }
            // if(mp[ch]==1){
            //     q.push_back(ch);
            //     ans+=q.front();
            // }
            // else if(ch == q.front()){
            //     q.pop_front();
            //     if(q.empty()) ans+='#';
            //     else{
            //         ans+=q.front();
            //     }
            // }
            // else{
            //     // q.pop_back();
            //     if(q.empty()) ans+='#';
            //     else{
            //         ans+=q.front();
            //     }
            // }
        }
        return ans;
    }
};
