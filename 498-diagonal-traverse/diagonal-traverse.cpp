class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<int>res;
        
        int sum = 0;
        bool up = true;
        while(sum<m+n-1){
            if(up){
                int i=sum<m?sum:m-1;
                int j=sum-i;
                while(i>=0 && j<n){
                    res.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                up=false;
            }else{
                int j=sum<n?sum:n-1;
                int i=sum-j;
                while(j>=0 && i<m){
                    res.push_back(mat[i][j]);
                    j--;
                    i++;
                }
                up=true;
            }

            sum++;
        }

        return res;
    }
};