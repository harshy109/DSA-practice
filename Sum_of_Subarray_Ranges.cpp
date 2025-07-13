class Solution {
public:
    void nextSmallerIndex(vector<int> &arr, vector<int> &nextAns){
        stack<int> s;
        s.push(-1);
        for(int i = arr.size()-1; i>=0; i--){
            int element = arr[i];
            while(s.top()!= -1 && arr[s.top()] > element){
                s.pop();
            }
            nextAns.push_back(s.top());
            s.push(i);
        }
    }
    void prevSmallerIndex(vector<int> &arr, vector<int> &prevAns){
        stack<int> s;
        s.push(-1);
        for(int i =0 ; i<arr.size(); i++){
            int element = arr[i];
            while(s.top()!= -1 && arr[s.top()] >= element){
                s.pop();
            }
            prevAns.push_back(s.top());
            s.push(i);
        }
    }
    long long sumSubarrayMins(vector<int>& arr) {

        vector<int> nextAns;
        vector<int> prevAns;

        nextSmallerIndex(arr, nextAns);
        reverse(nextAns.begin(), nextAns.end());

        for(int i = 0;  i<nextAns.size(); i++){
            if(nextAns[i]==-1){
                nextAns[i]=arr.size();
            }
        }
        prevSmallerIndex(arr, prevAns);
        long long sum = 0;
        for(int i = 0; i<arr.size(); i++){
            long long left = i-prevAns[i];
            long long right = nextAns[i] - i;
            sum += left*right*arr[i];
        }
        return sum;
    }

    void nextGreaterIndex(vector<int> &arr, vector<int> &nextAns){
        stack<int> s;
        s.push(-1);
        for(int i = arr.size()-1; i>=0; i--){
            int element = arr[i];
            while(s.top()!= -1 && arr[s.top()] < element){
                s.pop();
            }
            nextAns.push_back(s.top());
            s.push(i);
        }
    }
    void prevGreaterIndex(vector<int> &arr, vector<int> &prevAns){
        stack<int> s;
        s.push(-1);
        for(int i =0 ; i<arr.size(); i++){
            int element = arr[i];
            while(s.top()!= -1 && arr[s.top()] <= element){
                s.pop();
            }
            prevAns.push_back(s.top());
            s.push(i);
        }
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> nextAns;
        vector<int> prevAns;

        nextGreaterIndex(arr, nextAns);
        reverse(nextAns.begin(), nextAns.end());
        
        for(int i = 0;  i<nextAns.size(); i++){
            if(nextAns[i]==-1){
                nextAns[i]=arr.size();
            }
        }
        prevGreaterIndex(arr, prevAns);
        long long sum = 0;
        for(int i = 0; i<arr.size(); i++){
            long long left = i-prevAns[i];
            long long right = nextAns[i] - i;
            sum += left*right*arr[i];
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long sumOfMinimums = sumSubarrayMins(nums);
        long long sumOfMaximums = sumSubarrayMaxs(nums);

        return sumOfMaximums - sumOfMinimums;
    }
};
