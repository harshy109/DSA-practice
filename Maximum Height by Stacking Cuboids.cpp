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

    int solveTab(vector<vector<int>>& cuboids){
        int n = cuboids.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        //range
        //curr : 0 -> n
        //prev : -1 -> n
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                int inc = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])){
                    inc = cuboids[curr][2] + dp[curr+1][curr+1];
                }
                int exc = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(inc, exc);
            }
        }
        return dp[0][0];
    }
    int solveTabSO(vector<vector<int>>& cuboids){
        int n = cuboids.size();
        vector<int> prevRow(n+1, 0);
        vector<int> currRow(n+1, 0);

        //range
        //curr : 0 -> n
        //prev : -1 -> n
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                int inc = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])){
                    inc = cuboids[curr][2] + prevRow[curr+1];
                }
                int exc = 0 + prevRow[prev+1];
                currRow[prev+1] = max(inc, exc);
            }
            prevRow = currRow;
        }
        return prevRow[0];
    }    
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
        
        // int n = cuboids.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        //return solveMem(cuboids, curr, prev, dp);

        //return solveTabSO(cuboids);

        return solveTabSO(cuboids);
        
    }
};
