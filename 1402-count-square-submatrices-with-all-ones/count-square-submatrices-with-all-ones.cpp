class Solution {
public:
    int m,n;

    bool valid(int x,int y){
        return x-1>=0 && y-1>=0;
    }

    int countSquares(vector<vector<int>>& matrix) {
        m=matrix.size(), n=matrix[0].size();
        vector<vector<int>>res(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(valid(i,j) && matrix[i][j]==1){
                    res[i][j] = min({res[i-1][j-1],res[i][j-1],res[i-1][j]})==0?matrix[i][j]:min({res[i-1][j-1],res[i][j-1],res[i-1][j]})+1;
                }else{
                    res[i][j] = matrix[i][j];
                }
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans += res[i][j];
            }
        }

        return ans;
    }
};