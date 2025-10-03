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
    int trap(vector<int>& height) {
        vector<int> prevLargest;
        vector<int> nextLargest;
        populatePrevLargest(height, prevLargest);
        populateNextLargest(height, nextLargest);
        int totalWater = 0;

        for(int i = 0; i<height.size(); i++){
            int minOfTwo = min(prevLargest[i], nextLargest[i]);
            int h = 0;
            if(minOfTwo != 0){
                cout<<"minOfTwo :"<<minOfTwo<<" "<<"("<<prevLargest[i]<<", "<<nextLargest[i]<<")"<<endl;
                h = minOfTwo - height[i];
                cout<<i<<":"<<h<<endl;
            }
            totalWater += h;
        }
        return totalWater;
    }
};
