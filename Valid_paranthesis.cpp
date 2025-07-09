class Solution {
public:
    bool isValid(string s) {
        unordered_map <char, char> m;
        stack<char> st;
        m[')'] ='(';
        m[']'] = '[';
        m['}'] = '{';

        for(int i = 0; i< s.length(); i++){
            char ch = s[i];
            if(!st.empty() && m[ch]==st.top()){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }  
        return st.empty() ? true : false;
    }
};
