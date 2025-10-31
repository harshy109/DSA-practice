class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;

        priority_queue<int> pq;

        for(int i = 0; i<score.size(); i++){
            pq.push(score[i]);
        } 

        unordered_map<int, string> mp;
        int pos = 1;
        while(!pq.empty()){  
            if(pos==1) {
                int gold = pq.top();
                pq.pop();
                mp[gold] = "Gold Medal";
            }    
            else if(!pq.empty() && pos==2){
                int silver = pq.top();
                pq.pop();
                mp[silver] = "Silver Medal";
            }
            else if(!pq.empty() && pos==3){
                int bronze = pq.top();
                pq.pop();
                mp[bronze] = "Bronze Medal";
            }
            else{
                mp[pq.top()] = to_string(pos);
                pq.pop();
            }
            pos++;
        }
        for(auto it : score){
            ans.push_back(mp[it]);
        }
        return ans;

    }
};
