class Solution {
public:
    bool isPowerOfThree(int n) {
        //power of 3 : 1, 3,9, 27, 81, 243,
        if(n==0) return false;
        if(n == 1) return true;
        if(n%3 != 0) return false;
        int rem = n;
        n = (float)n;
        while( n >= 1 ){
            n = n / 3;
            rem = n%3; 
            cout<<n <<endl;
        }

        if(rem == 0) return true;
        return false;
    }
};
