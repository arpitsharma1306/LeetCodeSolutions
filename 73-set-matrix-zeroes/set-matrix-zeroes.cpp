class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<pair<int,int>>st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0) st.push_back({i,j});
            }
        }

        for(auto &it:st){
            int row=it.first, col=it.second;
            for(int j=0;j<n;j++){
                matrix[row][j]=0;
            }
            for(int i=0;i<m;i++){
                matrix[i][col]=0;
            }
        }

    }
};