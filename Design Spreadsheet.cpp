class Spreadsheet {
public:
    vector<vector<long long int>> grid;
    unordered_map<char, vector<int>> gridMap;

    long long int calci(long long int a, long long int b, char op){
        switch(op){
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            case '/': return a/b;
        }
        return 0;
    }
    Spreadsheet(int rows) {
        vector<vector<long long int>> grids(rows, vector<long long int>(26,0));
        this->grid = grids;
    }
    
    void setCell(string cell, int value) {
        int col = cell[0]-'A';
        string newStr = cell.substr(1);
        int row = 0;
        for(char ch : newStr){
            int rem = ch - '0';
            row = row*10 + rem;
        }
        grid[row-1][col] = value;
    }
    
    void resetCell(string cell) {
       int col = cell[0]-'A';
        string newStr = cell.substr(1);
        int row = 0;
        for(char ch : newStr){
            int rem = ch - '0';
            row = row*10 + rem;
        }
        grid[row-1][col] = 0;
    }
    
    int getValue(string formula) {
        int i = 1;
        int a = 0, b = 0;
        char op =' ';
            while(formula[i] >='0' && formula[i]<='9'){
                int rem = formula[i]-'0';
                a = a*10 + rem;
                i++;
            }
            if(i==1){
                int col = formula[i++]-'A';
                int row = 0;
                while(formula[i] >='0' && formula[i]<='9'){
                    int rem = formula[i]-'0';
                    row = row*10 + rem;
                    i++;
                }    
                a = grid[row-1][col];
            }
            op = formula[i++];
            while(formula[i] >='0' && formula[i]<='9'){
                int rem = formula[i]-'0';
                b= b*10 + rem;
                i++;
            }
            if(i<formula.length()){
                int col = formula[i++]-'A';
                int row = 0;
                while(formula[i] >='0' && formula[i]<='9'){
                    int rem = formula[i]-'0';
                    row = row*10 + rem;
                    i++;
                }  
                b = grid[row-1][col];
            }
        
        return calci(a, b, op);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
