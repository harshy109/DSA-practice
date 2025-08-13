// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int solve(int n){
        int s = n;
        int e = 1;
        int mid = e + (s-e)/2;
        int prev = n;
        int ans = prev;

        while(s>=e){
            if(isBadVersion(mid)){
                s = mid -1;
                prev = mid;
            }
            else{
               e = mid+1;
                
            }
            mid =  e + (s-e)/2;
        }
        return prev;
    }
    int firstBadVersion(int n) {
        //O(logn)
        return solve(n);
        //O(n)
        // if(n==1) return 1;
        // int prev = n;
        // for(int i = n; i>0;i--){
        //     if(!isBadVersion(i)){
        //         return prev;
        //     } 
        //     prev = i;
        // }
        // return prev;
    }
};
