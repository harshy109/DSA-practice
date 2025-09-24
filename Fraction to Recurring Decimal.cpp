class Solution {
public:
    int findDecimalPoint(string &s){
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '.'){
                return i;
            }
        }
        cout<<"did not find any ."<<endl;
        return -1;
    }
    string removeTrailingZeros(string s){
        int lastIntIndex = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] >= '1' && s[i] <='9'){
                lastIntIndex = i;
            }
        }
        string str = s.substr(0, lastIntIndex+1);
        cout<<str<<endl;
        return str;
    }
    string convertDecimalPart(string st){
        int mid = st.size()/2;
        string firstHalf = st.substr(0, mid);
        string secondHalf = st.substr(mid);
        string lastAns = "";
        string nonRepeatingPart="";
        bool noRepeat = true;
        for(int i = 0; i<st.length(); i++){
            string s = st.substr(i);
            nonRepeatingPart = st.substr(0,i);
            if(stoi(s) == 0){
                break;
            }
            while(firstHalf.size() != 0){
                int firstHalfToInt = stoi(firstHalf);
                int secondHalfToInt = stoi(secondHalf);
                if(firstHalfToInt == secondHalfToInt){
                    noRepeat = false;
                    lastAns = firstHalf;
                }
                mid--;
                firstHalf = s.substr(0, mid);
                secondHalf = s.substr(mid, mid);
            }
            if(noRepeat == )
        }
        if(noRepeat == true){
            return st;
        }
        lastAns = nonRepeatingPart +'(' + lastAns+ ')';
        return lastAns;
    }
    string fractionToDecimal(int numerator, int denominator) {
        double ans = (double)numerator /(double) denominator;
        string strAns = to_string(ans);
        cout<<strAns<<endl;

        //trim the string to remove trailing zeros  
        string finalStr =  removeTrailingZeros(strAns);
       
        int point = findDecimalPoint(finalStr);
        if(point == -1){
            return finalStr; 
            //to give answers  like 0.5, 2 , wihtout repeating
        }
        //for repeating fraction
        string fraction = strAns.substr(point+1);
        string newFraction = convertDecimalPart(fraction);
        if(newFraction == fraction) {
            return finalStr;
        }
        string finalAns = finalStr.substr(0, point+1) + newFraction; 
        // double fracDec = stoi(fraction);
        // if(fracDec == 0.0){
        //     return strAns.substr(0, point);
        // }
        return finalAns;      
    }
};
