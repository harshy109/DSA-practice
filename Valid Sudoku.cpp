class Solution {
public:
    bool checkAllConditions(vector<vector<char>>& board, int &r, int &c){
        char element = board[r][c];
        cout<<"element:"<<element<<endl;
        //row check
        for(int i = 0; i<9; i++){
            if(i!=c && board[r][i] == element){
                cout<<"Yaha ruka 1:"<<board[r][i]<<endl;
                return false;
            }
        }
        //column check
        for(int i = 0; i<9; i++){
            if(i!=r && board[i][c] == element){
                cout<<"Yaha ruka 2:"<<board[i][c]<<endl;
                return false;
            }
        }
        //box check
        int startRow = r - (r%3);
        int startCol = c - (c%3);
        cout<<"startCol:"<<startRow <<"startCol:"<<startCol<<endl;

        for(int i = startRow; i<startRow+3; i++){
            for(int j = startCol; j<startCol+3; j++){
                if(i!=r && j!=c && board[i][j] == element){
                    cout<<"Yaha ruka 3:"<<board[i][j]<<endl;
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
    
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] != '.'){
                    if(checkAllConditions(board,i, j)){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
