#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
     bool isPalindrome(string &s, int i, int j){
        //int i = 0, j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++, j--;
        } 
        return true;
     }
    string longestPalindrome(string s) {
        string ans="";
        //find all substrings -> check if isPalindrome -> yes -> check if longestPalindrome ? 
        //-> yes-> update ans
        for(int i= 0; i<s.length(); i++){
            for(int j = i; j<s.length(); j++){
                if(isPalindrome(s, i, j)){
                    string t = s.substr(i, j-i+1);
                    ans = t.length() > ans.length() ? t :ans;
                }
            }
        }
        return ans;
    }
};