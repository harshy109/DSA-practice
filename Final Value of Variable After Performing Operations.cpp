class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for(string s : operations){
            if(s[0] == 'X'){
                if(s[1] == '-'){
                    val--;
                }
                else if(s[1] == '+'){
                    val++;
                }
            }
            else if(s[0] == '+'){
                val++;
            }
            else if(s[0] == '-'){
                val--;
            }
            
        }

        return val;
    }
};

