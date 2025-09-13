class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ){
            return true;
        }
        return false;
    }
    int maxFreqSum(string s) {
        int ans = 0;

        unordered_map<char, int> vmap;
        unordered_map<char, int> cmap;

        for(char ch : s){
            if(isVowel(ch)){
               vmap[ch]++; 
            }
            else{
                cmap[ch]++;
            }
        }

        int cmax = 0;
        int vmax = 0;
        for(auto it1 : vmap){
            vmax = max(it1.second, vmax);
        }

        for(auto it2 : cmap){
            cmax = max(it2.second, cmax);
        }

        // if(cmax + vmax == INT_MIN){
        //     return 0;
        // }

        return cmax + vmax;

    }
};
