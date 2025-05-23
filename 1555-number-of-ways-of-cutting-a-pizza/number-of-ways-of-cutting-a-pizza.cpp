class Solution {
public:
    int m,n;
    vector<vector<int>> apple;
    vector<vector<vector<int>>>t;
    long long mod = 1e9+7;
    int solve(int i,int j,int k){
        if(apple[i][j]<k) return 0;
        if(k==1){
            return apple[i][j]>=1;
        }

        if(t[i][j][k]!=-1) return t[i][j][k];
        int ans = 0;
        //horizontal slicing
        for(int h=i+1;h<m;h++){
            int lower_slice = apple[h][j];
            int upper_slice = apple[i][j] - lower_slice;
            if(upper_slice>=1 && lower_slice>=k-1){
                ans = (ans%mod + solve(h,j,k-1)%mod)%mod; 
            } 
        }

        //vertical slicing
        for(int v=j+1;v<n;v++){
            int right_slice = apple[i][v];
            int left_slice = apple[i][j] - right_slice;
            if(left_slice>=1 && right_slice>=k-1){
                ans = (ans%mod + solve(i,v,k-1)%mod)%mod;
            }
        }

        return t[i][j][k] = ans;
    }
    int ways(vector<string>& pizza, int k) {
        m=pizza.size(), n=pizza[0].size();
        apple.resize(m+1,vector<int>(n+1,0));
        t.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                apple[i][j]=apple[i][j+1];
                for(int l=i;l<m;l++){
                    if(pizza[l][j]=='A'){
                        apple[i][j]++;
                    }
                }
            }
        }


        return solve(0,0,k);
    }
};