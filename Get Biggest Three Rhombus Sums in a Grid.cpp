class Solution {
public:
    bool checkBounds(vector<vector<int>>& grid,  vector<pair<int, int>>&v){
        int n = grid.size();
        int m = grid[0].size();

        for(auto pts : v){
            if(pts.first < 0 || pts.first >= n || pts.second < 0 || pts.second >= m){
                return false;
            }
        }
        return true;
    }
    bool getAllVertices(vector<vector<int>>& grid, vector<pair<int, int>>&v, pair<int, int> p, int delta){
        v[0] = {p.first - delta, p.second};
        v[1] = {p.first, p.second + delta};
        v[2] = {p.first + delta, p.second};
        v[3] = {p.first, p.second - delta};

        if(checkBounds(grid, v)){
            return true;
        }

        return false;
    }
    void getAllSums(vector<vector<int>>& grid, priority_queue<int> &pq, int &i, int &j){
        pq.push(grid[i][j]);

        vector<pair<int, int>> v(4);
        int delta = 1;
        while(getAllVertices(grid, v, {i, j}, delta)){
            pair<int,int>&A = v[0];
            pair<int,int>&B = v[1];
            pair<int,int>&C = v[2];
            pair<int,int>&D = v[3];

            int csum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];

            //all cells between A and B
            for(int i = 1; i<(B.first - A.first); i++){
                csum += grid[A.first+i][A.second+i];
            }
            //all cells between B and C
            for(int i = 1; i<(C.first - B.first); i++){
                csum += grid[B.first+i][B.second-i];
            }
            //all cells between C and D
            for(int i = 1; i<(C.first - D.first); i++){
                csum += grid[C.first-i][C.second-i];
            }
            //all cells between D and A
            for(int i = 1; i<(D.first - A.first); i++){
                csum += grid[D.first-i][D.second+i];
            }

            pq.push(csum);
            delta++;
        }
    }
    bool canPush(int element, vector<int> &ans){
        for(auto pt : ans){
            if(element == pt){
                return false;
            }
        }
        return true;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ans;
        priority_queue<int> pq;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                getAllSums(grid, pq, i, j);   
            }
        }

        //top 3 form pq
        while(!pq.empty() && ans.size()!=3){
            int element = pq.top();
            pq.pop();

            if(canPush(element, ans)){
                ans.push_back(element);
            }
        }

        return ans;

    }
};
