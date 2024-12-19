class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int k = distanceThreshold;
        vector<vector<int>>SPM(n,vector<int>(n,1e9+7));

        for(int i=0;i<n;i++){
            SPM[i][i]=0;
        }

        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            SPM[u][v]=w;
            SPM[v][u]=w;
        }

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    SPM[i][j]=min(SPM[i][j],SPM[i][via]+SPM[via][j]);
                }
            }
        }

        int mini = INT_MAX;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            int city = 0;
            for (int j = 0; j < n; j++) {
                if (abs(SPM[i][i] - SPM[i][j]) <= k)
                    city++;
            }
            if (city <= mini) {
                mini = city;
                ans = i;
            }
        }

        return ans;
    }
};