class Solution {
public:
    int solveRec(vector<int>& arr,map<pair<int, int>, int> &maxi, int s, int e){
        //base case
        if(s >= e){
            return 0;
        }

        int ans = INT_MAX;
        for(int i = s ; i<e; i++){
            int leftRangeKaMax = maxi[{s,i}];
            int rightRangeKaMax = maxi[{i+1, e}];
            int nonLeafValue = leftRangeKaMax*rightRangeKaMax;
            ans = min(ans, nonLeafValue + solveRec(arr, maxi, s, i) + solveRec(arr, maxi, i+1, e) );
        }
        return ans;
    }
    int solveMem(vector<int>& arr,map<pair<int, int>, int> &maxi, int s, int e, vector<vector<int>> &dp){
        //base case
        if(s >= e){
            return 0;
        }
        if(dp[s][e] != -1){
            return dp[s][e];
        }

        int ans = INT_MAX;
        for(int i = s ; i<e; i++){
            int leftRangeKaMax = maxi[{s,i}];
            int rightRangeKaMax = maxi[{i+1, e}];
            int nonLeafValue = leftRangeKaMax*rightRangeKaMax;
            ans = min(ans, nonLeafValue + solveMem(arr, maxi, s, i, dp) + solveMem(arr, maxi, i+1, e, dp));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }
    int solveTab(vector<int>& arr,map<pair<int, int>, int> &maxi){
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1, 0));

        //range : 
        //s : 0-> n
        //e : n-1 -> 0
        for(int s = n; s>=0; s--){
            for(int e = 0; e<=n-1; e++){
                if(s>=e){
                    continue;
                }
                else{
                    int ans = INT_MAX;
                    for(int i = s ; i<e; i++){
                        int leftRangeKaMax = maxi[{s,i}];
                        int rightRangeKaMax = maxi[{i+1, e}];
                        int nonLeafValue = leftRangeKaMax*rightRangeKaMax;
                        ans = min(ans, nonLeafValue + dp[s][i] + dp[i+1][e]);
                    }
                    dp[s][e] = ans;
                }
            }
        }
        return dp[0][n-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int, int>, int> maxi;

        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if( i == j){
                    maxi[{i,j}] = arr[j];
                }
                else{
                    maxi[{i,j}] = max(maxi[{i, j-1}], arr[j]);
                }
            }
        }

        int s = 0;
        int e = n-1;
        // return solveRec(arr,maxi, s, e);

        // vector<vector<int>> dp(n+1,vector<int>(n+1, -1));
        // return solveMem(arr, maxi, s, e, dp);

        return solveTab(arr, maxi);
    }
};
