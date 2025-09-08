class Solution {
  public:
    bool findPairs(vector<int>& arr) {
        unordered_map<int, int> map;
        
        for(int i = 0; i<arr.size(); i++){
            for(int j = i+1; j<arr.size(); j++){
                int sum = arr[i] + arr[j];
                map[sum]++;
                //optimizaton applied
                if(map[sum] == 2){
                    return true;
                }
            }
        }
        //TLE
        // for(auto it : map){
        //     if(it.second == 2){
        //         return true;
        //     }
        // }
        return false;
    }
};
