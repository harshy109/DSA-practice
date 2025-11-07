class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string s = countAndSay(n-1);
        int i = 0;
        string newStr = "";
        while(i<s.length()){
            int count = 1;
            int j = i+1;
            char ch = s[i];
            while(j<s.length() && s[j]==ch){
                count++;
                //i++;
                j++;
            }
            newStr += to_string(count) + ch;
            i=j;
            
        }
        return newStr;
    }
};
