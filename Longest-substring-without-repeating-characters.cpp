class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        int maxLen = INT_MIN;
        int i = 0;
        int j = i;
        unordered_map<char, int> mp;
        mp[i]++;
        //mp[j]++;
        
        while(i<s.length() && j <s.length()){
            mp[s[j]]++;
            if(mp[s[j]]==1){
                int len = j-i+1;
                maxLen = max(maxLen, len);
                j++;
            }
            else{
                mp[s[j]]--;
                //i=j;
                i++;
                j=i+1;
            }
        }
        return maxLen;
    }
};
