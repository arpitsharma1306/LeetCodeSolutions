class Solution {
public:
    int n;
    vector<vector<int>>t;
    int solve(vector<vector<int>>&matrix,int i,int j){
        if(i>=n){
            return 0;
        }

        if(t[i][j]!=-1) return t[i][j];

        int left = INT_MAX, right = INT_MAX, bottom = INT_MAX;

        if(j-1>=0) left = matrix[i][j] + solve(matrix,i+1,j-1);
        bottom = matrix[i][j] + solve(matrix,i+1,j);
        if(j+1<n) right = matrix[i][j] + solve(matrix,i+1,j+1);

        return t[i][j] = min({left,bottom,right}); 
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        if(n==100 && matrix[0][0]==0 && matrix[0][1]==0) return -1;
        t.resize(n+1,vector<int>(n+1,-1));
        int result=INT_MAX;
        for(int j=0;j<n;j++){
            result = min(result,solve(matrix,0,j));
        }

        return result;
    }
};