class Solution {
public:
    int myAtoi(string s) {
        int num=0;
        bool neg=false;
        int sign = 1;
        int i = 0;
        //1.leading spaces
        while(s[i]==' '){
            i++;
        }
        //2.check negativity
        if(s[i]=='-'){
            neg=true;
            sign = -1;
            i++;
        }
        //neg = s[i]=='-' ? true : false;

        //edge case = "-+12"-> 0
        if(s[i]=='+'){
            if(neg){
                return 0;
            }
            i++;
        }
        //3. zeros
        while(s[i]=='0'){
            i++;
        }
        while(i<s.length()){  
            
            //main transformation
            if(s[i]>=48 && s[i]<=57){
                int n = s[i]-'0';
                //long int extraNum = (num*10)+n;
                if(num>(INT_MAX/10) || (num==INT_MAX/10 && n>7 )){
                    return neg? INT_MIN: INT_MAX;
                }
                if(num*sign < INT_MIN/10 || (num<INT_MIN/10 && n>8)){
                    return INT_MIN;
                }
                num = num*10 + n;
            }
            else{
                break;
            }
            i++;
        }
        if(neg){
            num*=-1;
        }

        return num;
    }
};

