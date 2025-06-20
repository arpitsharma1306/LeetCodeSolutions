class Solution {
public:
    bool allLessEqualOne(const vector<double>& row) {
        for (double x : row) {
            if (x > 1) return false;
        }
        return true;
    }
    double champagneTower(double poured, int query_row, int query_glass) {
        vector<double>cups;
        if(query_row==0) return poured>=1?1:poured;
        cups.push_back({poured});
        while(!allLessEqualOne(cups)){
            int col = cups.size();
            vector<double>new_row(col+1,0);
            for(int j=0;j<col;j++){
                double water = cups[j] - 1;
                if(water>0){
                    new_row[j] += water/2;
                    new_row[j+1] += water/2; 
                } 
            }
            if(col==query_row){
                return new_row[query_glass]>=1?1:new_row[query_glass];
            }
            cups = new_row;
            
        }

        return 0;
    }
};