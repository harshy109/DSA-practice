class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> m;
        int largestLucky = -1;
        for(int i = 0; i<arr.size(); i++){
            m[arr[i]]++;
        }
        for(auto it : m){
            if(it.first == it.second){
                //return it.first;
                largestLucky = max(it.first, largestLucky);
                
            }
        }
        return largestLucky;
    }
};
