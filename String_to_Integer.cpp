//Leetcode 8. String to Integer (atoi)
class Solution {
public:
    int myAtoi(string s) {
        int num=0;
        bool neg=false;
        int i = 0;

        while(s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            neg=true;
            i++;
        }
        if(s[i]=='+'){
            if(neg){
                return 0;
            }
            i++;
        }
        while(s[i]=='0'){
            i++;
        }
        while(i<s.length()){  
            
            //main transformation
            if(s[i]>=48 && s[i]<=57){
                int n = s[i]-'0';
                //long int extraNum = (num*10)+n;
                if(num >= (INT_MAX - n)/10){
                    return neg? INT_MIN: INT_MAX-1;
                }
                num = num*10 + n;
            }
            else{
                break;
            }
            i++;
        }
        if(num>=INT_MAX){
            num=INT_MAX-1;
        }
        // else if(num<INT_MIN){
        //     num=INT_MIN+1;
        // }
        //check negativity
        if(neg){
            num*=-1;
        }

        return num;
    }
};
