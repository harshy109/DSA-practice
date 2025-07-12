class Solution {
public:
    void nextSmaller(vector<int>& heights, vector<int> &nextAns){
        stack<int> s;
        s.push(-1);
        int n = heights.size();

        for(int i = n-1; i>=0; i--){
            int element = heights[i];
            //int index = s.top();
            while(s.top()!=-1 && heights[s.top()] >= element){
                s.pop();
            }
            nextAns.push_back(s.top());
            s.push(i);
        }
    }

     void prevSmaller(vector<int>& heights, vector<int> &prevAns){
        stack<int> s;
        s.push(-1);
        int n = heights.size();

        for(int i = 0; i<n; i++){
            int element = heights[i];
            while(s.top()!=-1 && heights[s.top()] >= element){
                s.pop();
            }
            prevAns.push_back(s.top());
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {

        vector<int> nextAns;
        vector<int> prevAns;

        nextSmaller(heights, nextAns);
        reverse(nextAns.begin(), nextAns.end());
        for(int i = 0; i<nextAns.size(); i++){
            if(nextAns[i] == -1){
                nextAns[i] = heights.size();
            }
        }

        prevSmaller(heights, prevAns);

        int maxArea = INT_MIN;
        for(int i = 0; i<nextAns.size(); i++){
            int width = nextAns[i] - prevAns[i] - 1;
            int area = heights[i] * width;
            maxArea = max(area, maxArea);

        }
        return maxArea;

        
//solved with 93/99 test cases passed
        // int maxArea = INT_MIN;
        // for(int i = 0; i<heights.size(); i++){
        //     int length = heights[i];
        //     int width = 1;
        //     int leftI=i-1,rightI=i+1;

        //     while(leftI>=0 && heights[leftI--] >= length){
        //         width++;
        //     }
        //     while(rightI<heights.size() && heights[rightI++] >= length){
        //         width++;2
        //     }
        //     int area = length*width;
        //     maxArea = max(maxArea, area);

        // }
        // return maxArea;
    }
};
