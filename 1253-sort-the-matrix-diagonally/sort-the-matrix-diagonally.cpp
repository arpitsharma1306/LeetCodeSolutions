class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[j-i].push_back(mat[i][j]);
            }
        }

        for(auto &it:mp){
            sort(begin(it.second),end(it.second));
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                mat[i][j]=mp[j-i].back();
                mp[j-i].pop_back();
            }
        }

        return mat;
    }
};