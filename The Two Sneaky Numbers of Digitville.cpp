class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> v;

        for(auto it : nums){
            mp[it]++;
        }
        for(auto itr : mp ){
            if(itr.second == 2){
                v.push_back(itr.first);
            }
        }
        return v;
    }
};
