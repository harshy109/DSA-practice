//6. Zigzag Conversion
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length()<numRows) return s;

        vector<string> row(numRows);
        int i  = 0;
        int r = 0;
        bool down=false;
        while(i<s.length()){
            row[r]+=s[i++];

            if(r==0 || r==numRows-1){
                down=!down; //change direction at top and bottom
            }

            r+=down?1:-1;

            // while(r<numRows && i<s.length()){
            //     row[r++].push_back(s[i++]);
            // }
            // r = numRows-2;
            // while(r>=0  && i<s.length()){
            //     row[r--].push_back(s[i++]);
            // }
        }

        string ans = "";
        for(int i = 0; i<row.size(); i++){
            ans+=row[i];
        }
        return ans;
    }
};

//Starting approach

// class Solution {
// public:
//     string convert(string s, int numRows) {
//         string ans="";
        
//         if(s.length()==1){
//             return s;
//         }
//         int estC = (s.length()/numRows)+numRows;
//         int index  = 0;
//         vector<vector<char>> v(numRows, vector<char>(estC, '-'));
//         int r=0, c=0;
//         //filling 2d array
//         //start from c = 0;
//         while(index < s.length() && c<estC){
//             if((c%(numRows-1))==0){
//                 r=0;
//                 while(r<numRows && c<estC){
//                     v[r++][c]=s[index++];
//                 }
//                 c++;
//                 r--;
//             }
//             else{
//                 while(r>0 && c<estC){
//                     v[--r][c++]=s[index++];
//                 }
//             }
//         }



//         for(int i = 0; i<v.size(); i++){
//             for(int j = 0; j<v[i].size(); j++){
//                 if(v[i][j]!='-'){
//                     ans+=v[i][j];
//                 }
//             }
//         }
//         return ans;
        
//     }
// };
