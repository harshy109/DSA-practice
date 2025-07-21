class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string ans = "";

        // solve(s,i, ans,"", st);
        int i = 0;
        while(i<s.length()){
            if(s[i]==']'){
                string temp = "";
                while(!st.empty() && st.top()!="["){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();

                string numericString = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    numericString+=st.top();
                    st.pop();
                }
                reverse(numericString.begin() , numericString.end());
                int num = stoi(numericString);

                string newStr = "";
                while(num--){
                    newStr+=temp;
                }

                st.push(newStr);
                i++;
            }
            else{
                string str(1, s[i++]);
                st.push(str);
            }
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;

        // int i = 0;
        // while(i<s.length()){
        //     char ch = s[i];
        //     int count = 0;
        //     if(ch>='0' && ch<='9'){
        //         count = ch-'0';
        //         i++;
        //     }
        //     if(s[i]=='[') i++;
        //     string str;
        //     while(s[i]!=']'){
        //         str+=s[i++];
        //     }
        //     while(count--){
        //         ans+=str;
        //     }
        
        // }
        // return ans;
    }
};
