class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz=original.size();
        vector<vector<int>>empty;
        vector<vector<int>>arr(m,vector<int>(n));
        if(m*n!=sz) return empty;
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=original[k];
                k++;
            }
        }

        return arr;
    }
};