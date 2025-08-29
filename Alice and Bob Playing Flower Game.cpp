class Solution {
public:
    long long flowerGame(int n, int m) {

        //O(n2)
        //long long count = 0;
        
        // for(int i=1; i<=n; i++){
        //     for(int j = 1; j<=m; j++){
        //         //v.push_back(make_pair(i,j));
        //         int sum = i+j;
        //         if(sum%2 != 0){
        //             count++;
        //         }
        //     }
        // }

        //Optimized approach with TC = O(n)
        long long oddX = 0;
        long long evenX = 0;
        long long oddY = 0;
        long long evenY = 0;

        for(int i = 0; i<n; i++){
            if(i%2 != 0){
                oddX++;
            }
            else{
                evenX++;
            }
        }
        for(int i = 0; i<m; i++){
            if(i%2 != 0){
                oddY++;
            }
            else{
                evenY++;
            }
        }

        long long combA = oddX * evenY;
        long long combB = evenX * oddY;

        return combA+combB;
    }
};
