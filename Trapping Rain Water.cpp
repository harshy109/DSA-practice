class Solution {
public:
    void populatePrevLargest(vector<int>& height, vector<int>& prevLargest){
        for(int i = 0; i<height.size(); i++){
            int j = i-1;
            int maxHeight = height[i];
            while(j>=0){
                if(height[j] > maxHeight ){
                    maxHeight = height[j];
                    
                }
                j--;
            }
            if(maxHeight == height[i]){
                prevLargest.push_back(0);
            }
            else{
                prevLargest.push_back(maxHeight);   
            }
        }
        return;
    }
    void populateNextLargest(vector<int>& height, vector<int>& nextLargest){
        for(int i = 0; i<height.size(); i++){
            int j = i+1;
            int maxHeight = height[i];
            while(j<height.size()){
                if(height[j] > maxHeight){
                    maxHeight = height[j];
                    
                }
                j++;
            }
            if(maxHeight == height[i]){
                nextLargest.push_back(0);
            }
            else{
                nextLargest.push_back(maxHeight);   
            }
            
        }
        return;
    }
    int findPrevLargestWithRec(vector<int>& height, int i, int j, int maxHeight){
        //base case
        if(j<0){
            if(maxHeight == height[i]){
                return 0;
            }
            else{
                return maxHeight;   
            }
        }
        
        if(height[j] > maxHeight ){
            maxHeight = height[j];    
        }
        return findPrevLargestWithRec(height, i, j-1, maxHeight);
    }
    int findNextLargestWithRec(vector<int>& height, int i, int j, int maxHeight){
        //base case
        if(j>=height.size()){
            if(maxHeight == height[i]){
                return 0;
            }
            else{
                return maxHeight;   
            }
        }
        
        if(height[j] > maxHeight ){
            maxHeight = height[j];    
        }
        return findNextLargestWithRec(height, i, j+1, maxHeight);
    }
    int findPrevLargestWithMem(vector<int>& height, int i, int j, int maxHeight, vector<vector<int>>& dp){
        //base case
        if(j<0 && maxHeight <=dp[0].size()){
            if(maxHeight == height[i]){
                dp[j+1][maxHeight] = 0;
            }
            else{
                dp[j+1][maxHeight] = maxHeight;    
            }
            return dp[j+1][maxHeight];
        }
        if(dp[j+1][maxHeight] != -1){
            return dp[j+1][maxHeight];
        }
        
        if(height[j] > maxHeight ){
            maxHeight = height[j];    
        }
        return findPrevLargestWithMem(height, i, j-1, maxHeight, dp);
    }
    int findNextLargestWithMem(vector<int>& height, int i, int j, int maxHeight, vector<vector<int>>& dp){
        //base case
        if(j>=height.size()  && maxHeight <=dp[0].size()){
            if(maxHeight == height[i]){
                dp[j+1][maxHeight] = 0;
            }
            else{
                dp[j+1][maxHeight] = maxHeight;
            }
            return dp[j+1][maxHeight];
        }
        if(dp[j+1][maxHeight] != -1){
            return dp[j+1][maxHeight];
        }
        
        if(height[j] > maxHeight ){
            maxHeight = height[j];    
        }
        return findNextLargestWithMem(height, i, j+1, maxHeight, dp);
    }
    int findMaxElement(vector<int>&height){
        int maxE = INT_MIN;
        for(int i = 0; i<height.size(); i++){
            maxE = max(maxE, height[i]);
        }
        return maxE;
    }
    int trap(vector<int>& height) {
        int totalWater = 0; 

        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i = 1; i<n; i++){
            left[i] = max(left[i-1], height[i]);
        }
        for(int i = n-2; i>=0; i--){
            right[i] = max(right[i+1], height[i]);
        }

        
        for(int i = 0; i<n; i++){
            int minOfTwo = min(left[i], right[i]);
            int h = 0;
            if(minOfTwo != 0){
                h = minOfTwo - height[i];
            }
            totalWater += h;
        }

        // populatePrevLargest(height, prevLargest);
        // populateNextLargest(height, nextLargest);
        

        //first approach
        // vector<int> prevLargest;
        // vector<int> nextLargest;
        // for(int i = 0; i<height.size(); i++){
        //     int minOfTwo = min(prevLargest[i], nextLargest[i]);
        //     int h = 0;
        //     if(minOfTwo != 0){
        //         //cout<<"minOfTwo :"<<minOfTwo<<" "<<"("<<prevLargest[i]<<", "<<nextLargest[i]<<")"<<endl;
        //         h = minOfTwo - height[i];
        //         //cout<<i<<":"<<h<<endl;
        //     }
        //     totalWater += h;
        // }

        //rec
        // for(int i = 0; i<height.size(); i++){
        //     int prevLargestElement = findPrevLargestWithRec(height, i, i-1, height[i]);
        //     int nextLargestElement = findNextLargestWithRec(height, i, i+1, height[i]);
        //     int minOfTwo = min(prevLargestElement, nextLargestElement);
        //     int h = 0;
        //     if(minOfTwo != 0){
        //         h = minOfTwo - height[i];
        //     }
        //     totalWater += h;
        // }

        //mem
        // int n = height.size();
        // int maxElement = findMaxElement(height);
        // vector<vector<int>> dp(n+2, vector<int>(maxElement+1, -1));
        // for(int i = 0; i<height.size(); i++){
        //     int prevLargestElement = findPrevLargestWithMem(height, i, i-1, height[i], dp);
        //     int nextLargestElement = findNextLargestWithMem(height, i, i+1, height[i], dp);
        //     int minOfTwo = min(prevLargestElement, nextLargestElement);
        //     int h = 0;
        //     if(minOfTwo != 0){
        //         h = minOfTwo - height[i];
        //     }
        //     totalWater += h;
        // }

        return totalWater;
    }
};
