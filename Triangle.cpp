class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col){
       if(row==triangle.size()-1){
            return triangle[row][col];
       }

       int down = triangle[row][col] + solve(triangle, row+1,col);
       int plus = triangle[row][col] + solve(triangle, row+1,col+1);
        return min(down, plus);
    }



    int solveRec(vector<vector<int>>& triangle, int row, int i){
        //base case
        if(row >= triangle.size()){
            return 0;
        }
        if(i >= triangle[row].size()){
            return 0;
        }

        // vector<int> v = triangle[row];

        int first = triangle[row][i] + solveRec(triangle, row+1, i);
        int second = INT_MAX;
        if(i+1 < triangle[row].size()){
            second = triangle[row][i+1] + solveRec(triangle, row+1, i+1);
        }
        int ans = min(first, second);
        return ans;
    }
    int solveMem(vector<vector<int>>& triangle, int row, int i, vector<vector<int>> &dp){
        //base case
        if(row >= triangle.size()){
            return 0;
        }
        if(i >= triangle[row].size()){
            return 0;
        }
        if(dp[row][i] != -1){
            return dp[row][i];
        }

        int first = triangle[row][i] + solveMem(triangle, row+1, i, dp);
        int second = INT_MAX;
        if(i+1 < triangle[row].size()){
            second = triangle[row][i+1] + solveMem(triangle, row+1, i+1 ,dp);
        }
        dp[row][i] = min(first, second);
        return dp[row][i];
    }

    int solveTab(vector<vector<int>>& triangle){
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m+2, vector<int> (n+2, 0));

        for(int row = m-1; row>=0; row--){
            int col = triangle[row].size(); 
            for(int i = col-1; i>=0; i--){
                int first = triangle[row][i] + dp[row+1][i];
                int second = INT_MAX;
                if(i+1 < triangle[row].size()){
                    second = triangle[row][i+1] + dp[row+1][i+1];
                }
                dp[row][i] = min(first, second);
            }
        }
        return dp[0][0];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        //return solve(triangle, 0,0);
        
        // int m = triangle.size();
        // int n = triangle[m-1].size();
        // vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        // return solveMem(triangle, 0, 0, dp);

        return solveTab(triangle);
    }
};
