class Solution {
public:
    long long flowerGame(int n, int m) {
        //vector<pair<int,int>> v;
        
        long long count = 0;
        
        for(int i=1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                //v.push_back(make_pair(i,j));
                int sum = i+j;
                if(sum%2 != 0){
                    count++;
            }
            }
        }
        // long long count = 0;
        // for(auto pt : v){
        //     int sum = pt.first + pt.second;
        //     if(sum%2 != 0){
        //         count++;
        //     }
        // }
        return count;
    }
};
