class Solution {
public:
    bool solve(vector<int>& v, string &s, char &turn) {
        if (s.empty()) {
            if(turn =='A'){
                return false;
            }
            else{
                return true;
            }
        }

        v.clear();
        int vowelCount = 0;
        int lastOddIndex = 0;
        int lastOdd = 0;
        int firstEvenCount = 0;
        int firstEvenIndex = 0;

        for (int i = 0; i<s.length();i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            }
            v.push_back(vowelCount);
            if (v.back() % 2 != 0) {
                lastOdd = v.back();
                lastOddIndex = i;
            }
            if(vowelCount%2 == 0 && firstEvenCount == 0){
                firstEvenIndex = i;
            }
        }

        // if no vowels -> Bob wins
        if (turn=='B' && vowelCount == 0) {
            return false;
        }
        else if(turn=='B' && vowelCount%2 != 0){
            return true;
        }
        // if odd numbers ->ALice wins
        if (turn=='A' && vowelCount % 2 != 0) {
            return true;
        }

        if (turn == 'A') {
            s = s.substr(lastOddIndex);
            turn  = 'B';
            return solve(v, s, turn);
        }
            s = s.substr(firstEvenIndex);
            turn = 'A';
            return solve(v, s, turn);
    }
    bool doesAliceWin(string s) {
        // vector<int> v;
        // char turn = 'A'; 
        // bool ans = solve(v, s, turn);
        // return ans;

        int vowelCount = 0;
        for (int i = 0; i<s.length();i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            }
        }
        if(vowelCount == 0) return false;
        return vowelCount > 0;

    }
};
