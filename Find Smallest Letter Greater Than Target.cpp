class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;
        int minDist = INT_MAX;
        char finalAns = arr[0];

        while(s<=e){
            if(target < arr[mid]){
                int ans = arr[mid] - target;
                if(ans < minDist && ans>0){
                    finalAns = arr[mid];
                }
                e=mid-1;
            }
            else if(arr[mid]==target || target > arr[mid]){
                int ans = arr[mid] - target;
                if(ans < minDist && ans>0){
                    finalAns = arr[mid];
                }
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return finalAns;
    }
};
