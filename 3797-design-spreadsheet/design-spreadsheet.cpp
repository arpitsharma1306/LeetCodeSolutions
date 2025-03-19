class Spreadsheet {
private:
    pair<int,int> getPos(string cell) {
        int r = cell[0]-'A'; // convert column letter to index (A -> 0, B -> 1, ...)
        int c = stoi(cell.substr(1)) - 1; // extract row number and make it 0-indexed
        return {r, c};
    }
public:
    vector<vector<int>> matrix;
    Spreadsheet(int rows) {
        matrix.resize(26);
        for(int i = 0; i < 26; i++){
            matrix[i].resize(rows);
        }
    }
    
    void setCell(string cell, int value) {
        pair<int,int> p = getPos(cell);
        matrix[p.first][p.second] = value;
    }
    
    void resetCell(string cell) {
        pair<int,int> p = getPos(cell);
        matrix[p.first][p.second] = 0;
    }
    
    int getValue(string formula) {
        string num1, num2;
        int i = 1;
        while(formula[i] != '+') num1 += formula[i++];  // num1 -> after "=" and before "+"
        num2 = formula.substr(i+1);  // num2 -> after "+"
        
        int x, y;
        if(num1[0] >= 'A' && num1[0] <= 'Z'){  // extract cell value
            pair<int,int> p = getPos(num1);
            x = matrix[p.first][p.second];
        }
        else x = stoi(num1);   // direct value
        
        if(num2[0] >= 'A' && num2[0] <= 'Z'){
            pair<int,int> p = getPos(num2);
            y = matrix[p.first][p.second];
        }
        else y = stoi(num2);
        
        return x + y;
    }
};