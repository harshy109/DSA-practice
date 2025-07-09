class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        int hasRedundantBracket = 0;
        stack<char> st;
        
        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                st.push(ch);
            }
            else if(ch >= 'a' && ch<='z' || ch >= 'A' && ch<='Z'){
                continue;
            }
            else if(ch == ')' && (st.top() == '+' || st.top() == '-' ||st.top() == '*' ||st.top() == '/')){
                while(st.top()!='('){
                    st.pop();
                }
                st.pop();
            }
            else if(ch == ')' && st.top() == '('){
                hasRedundantBracket = 1;
                break;
            }
        }
        return hasRedundantBracket ;
    }
};
