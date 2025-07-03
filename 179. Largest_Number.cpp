179. Largest Number
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s="";
        vector<vector<char>> v;
        //insert into 2d array
        int maxLen = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            string str = a[i]+'0';
            for(int j = 0; j<str.length(); j++){
                v[i][j]=str[j];
                maxLen = max(maxLen, j);
            }
        }

        int maxi = INT_MIX:
        //compare first value
        for(int j = 0; j<maxLen; j++){
            for(int i = 0; i<v.size(); i++){
                maxi = max(maxi, v[i][j]);
            }
        }
        return s;    
    }
};
