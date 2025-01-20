class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,pair<int,int>>mp;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                mp[mat[row][col]]={row,col};
            }
        }

        vector<int>freq_row(m,0);
        vector<int>freq_col(n,0);
        
        for(int i=0;i<arr.size();i++){
            int row=mp[arr[i]].first;
            int col=mp[arr[i]].second;
            freq_row[row]++;
            freq_col[col]++;
            if(freq_row[row]==n) return i;
            if(freq_col[col]==m) return i; 
        }

        return -1;
    }
};