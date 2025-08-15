class Solution {
public:
    bool solve(long long n, long long prevRem){
        if(prevRem != 0){
            return false;
        }
        if(n<=1 && prevRem == 0){
            return true;
        }
        else if(n<=1 && prevRem != 0){
            return false;
        }
        double d = n;
        return solve(d/4, n%4);
    }
    bool isPowerOfFour(long long n) {
        if(n<=0) return false;
        double num= n;
        return solve(num,0);
    }
};
