class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //priority_queue<pair<int, int>> q;
        priority_queue<int> q;
        unordered_map<int, int> mp;
        //insert into map
        for(auto n : nums){
            mp[n]++;
        }
        //insert into heap
        for(auto it : mp){
            q.push(it.second);
        }
        // to store ans
        vector<int> ans;
        while(k--){
            int val = q.top();
            for(auto m : mp){
                if( m.second == val){
                    ans.push_back(m.first);
                    q.pop();
                    mp.erase(m.first);
                    break;
                }
            }
        }
        return ans;
    }
};
