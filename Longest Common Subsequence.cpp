class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        int count=0;
        int flag=0;
        if(text1.size() > text2.size()){
            while(i<text1.size()){
                if(text1[i] == text2[j]){
                    count++;
                    flag = j++;
                    i++;
                }
                else if(j == text2.size()-1){
                    i++;
                    j=flag;
                }
                else {
                    j++;
                }
            }
        }
        else{
            while(i<text1.size()){
                if(text1[i] == text2[j]){
                    count++;
                    flag = i++;
                    j++;
                }
                else if(i == text1.size()-1){
                    j++;
                    i=flag;
                }
                else {
                    i++;
                }
            }
        }
        
        return count;
    }
};
