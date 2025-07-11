class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

//solved with 93/99 test cases passed
        int maxArea = INT_MIN;
        for(int i = 0; i<heights.size(); i++){
            int length = heights[i];
            int width = 1;
            int leftI=i-1,rightI=i+1;

            while(leftI>=0 && heights[leftI--] >= length){
                width++;
            }
            while(rightI<heights.size() && heights[rightI++] >= length){
                width++;
            }
            int area = length*width;
            maxArea = max(maxArea, area);

        }
        return maxArea;
    }
};
