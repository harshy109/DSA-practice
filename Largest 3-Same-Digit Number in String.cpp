class Solution {
public:
    string largestGoodInteger(string num) {
        int i = 0;
        vector<string> v;
        int finalNum = INT_MIN;
        string finalAns = "";
        while(i < num.length()){
            int j = i+1;
            int n = 2;
            string goodInt = "";
            goodInt += num[i];
            while(num[i]==num[j] && n){
                goodInt += num[j];
                j++;
                n--;
            }
            cout<<goodInt<<endl;
            if(n==0){
                int numb = std::stoi(goodInt);
                finalNum = max(finalNum, numb);
                if(finalNum == numb){
                    finalAns = goodInt;
                }
                else{
                    finalAns = to_string(finalNum);
                }
                cout<<finalNum<<" "<<finalAns<<endl;
                i = j;
            }
            else{
                i++;
            }
        }
        return finalAns;
    }
};
