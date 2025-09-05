
class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // unordered_map<int,int> bmp;
        // unordered_map<int,int> amp;
        
        
        // for(int i=0;i<b.size(); i++){
        //     bmp[b[i]]++;
        // }
        
        // for(int i=0; i<a.size(); i++){
        //     if(bmp.find(a[i]) != bmp.end() && bmp[a[i]]>0){
        //         bmp[a[i]]--;
        //     }
        // }
        
        // for(auto it : bmp){
        //     if(it.second != 0){
        //         return false;
        //     }
        // }
        
        
        unordered_map<int,int> map;
        
        for(int i =0; i<a.size(); i++){
            map[a[i]]++;
        }
        
        for(int i =0; i<b.size(); i++){
            if(map.find(b[i]) == map.end()){
                return false;
            }
            else{
                if(map[b[i]] > 0){
                    map[b[i]]--;
                }
                else{
                    return false;
                }
            }
        }
        
        
        return true;
    }
};
