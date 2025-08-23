class Solution {
public:
    float calculateDistance(int x, int y){


        float ans = sqrt(x*x + y*y)*1.0;
        return ans;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority_queue<float, vector<float>, greater<float>> pq;
        priority_queue<pair<float, vector<int>>, vector<pair<float, vector<int>>>, greater<pair<float, vector<int>>> > pq;
        //unordered_map<float, vector<int>> mp;

        for(auto p : points){
            float dist = calculateDistance(p[0], p[1]);
            pq.push({dist,p});
            //mp[Dist] = p;
        }
        vector<vector<int>> ans;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop()
        }
        return ans;
    }
};
