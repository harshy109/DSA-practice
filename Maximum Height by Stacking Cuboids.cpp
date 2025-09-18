class Solution {
public:
    bool isSafeToPlace(vector<int> c1, vector<int> c2){
        if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2]){
            return true;
        }
        return false;
    }
    int solveRec(vector<vector<int>>& cuboids, int curr, int prev){
        //base case
        if(curr >= cuboids.size()){
            return 0;
        }

        int inc = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])){
            inc = cuboids[curr][2] + solveRec(cuboids, curr+1, curr);
        }
        int exc = 0 + solveRec(cuboids, curr+1, prev);
        int ans = max(inc, exc);
       
        return ans;
    }
    int solveMem(vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>> &dp){
        //base case
        if(curr >= cuboids.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int inc = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])){
            inc = cuboids[curr][2] + solveMem(cuboids, curr+1, curr, dp);
        }
        int exc = 0 + solveMem(cuboids, curr+1, prev, dp);
        dp[curr][prev+1] = max(inc, exc);

        return dp[curr][prev+1];
    }//2D dp
    int maxHeight(vector<vector<int>>& cuboids) {
        //sorting level 1 : individual sorting
        for(auto &cuboid : cuboids){
            sort(cuboid.begin(), cuboid.end());
        }

        //sorting level 2 : whole array
        sort(cuboids.begin(), cuboids.end());

        int curr = 0;
        int prev = -1;
        // return solveRec(cuboids, curr, prev);
        
        int n = cuboids.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solveMem(cuboids, curr, prev, dp);
    }
};
