class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        int maxCount=0;

        for(auto &currRows:matrix){
            vector<int>inverted(n);

            for(int col=0;col<n;col++){
                inverted[col] = currRows[col] == 0 ? 1 : 0;
            }
            int count=0;
            for(auto &row:matrix){
                if(row==currRows || row==inverted){
                    count++;
                }
            }
            maxCount=max(maxCount,count);
        }

        return maxCount;
    }
};