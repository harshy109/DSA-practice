class Solution {
    static bool comp(pair<char, int> p, pair<char, int> q){
        return p.first < q.first;
    }
public:

    bool isVowel(char ch){
        if(ch =='A' || ch =='E'||ch =='I'||ch =='O'||ch =='U'|| ch=='a' || ch=='e' ||ch =='i'||ch =='o'||ch =='u'){
            return true;
        }
        return false;
    }
    string sortVowels(string &s) {
        vector<char> varr;
        vector<char> carr;
        vector<char> mark;
        string t = "";

        for(char ch : s){
            if(isVowel(ch)){
                varr.push_back(ch);
                mark.push_back('v');
            }
            else{
                carr.push_back(ch);
                mark.push_back('c');
            }
        }

        sort(varr.begin(), varr.end());
        
        int i = 0;
        int j = 0;
        for(int index = 0; index<mark.size(); index++){
            if(mark[index] == 'v'){
                t+=varr[i];
                i++;
            }
            else{
                t+=carr[j];
                j++;
            }
        }

        return t;




        // string t = "";
        // vector<pair<char, int>> v;

        // for(int i = 0; i<s.length();i++){
        //     char ch = s[i];
        //     if(ch =='A' || ch =='E'||ch =='I'||ch =='O'||ch =='U'|| ch=='a' || ch=='e' ||ch =='i'||ch =='o'||ch =='u'){
        //         v.push_back({ch, i});
        //     }
        // }

        // sort(v.begin(), v.end());

        // for(int i=0;i<v.size(); i++ ){
        //     int index = v[i].second;
        //     char ch = v[i].first;

        //     s[index] = ch;
        // }

        // return s;
    }
};
