class Solution {
public:
    int m,n;

    int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&t){
        if(i>=m || j>=n){
            return 0;
        }

        if(matrix[i][j]==0){
            return 0;
        }

        if(t[i][j]!=-1){
            return t[i][j];
        }

        int right=solve(matrix,i,j+1,t);
        int diagonal=solve(matrix,i+1,j+1,t);
        int down=solve(matrix,i+1,j,t);

        return t[i][j]=1+min({right,diagonal,down});
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();

        vector<vector<int>>t(m+1,vector<int>(n+1,-1));

        int result=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result+=solve(matrix,i,j,t);
            }
        }

        return result;
    }
};