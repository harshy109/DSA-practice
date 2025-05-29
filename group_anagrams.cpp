#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy=strs;
        vector<vector<string>> ans;
        for(int i = 0 ; i<copy.size(); i++){
            sort(copy[i].begin(), copy[i].end());
        }

        unordered_set<string> table;
        for(int i = 0; i<copy.size(); i++){
            table.insert(copy[i]);
        }
        
        for(auto it:table){
            vector<string> match;
            for(int i = 0; i<copy.size(); i++){
                if(it==copy[i]){
                    match.push_back(strs[i]);
                }
            }
            ans.push_back(match);
        }
        return ans;
    }
};