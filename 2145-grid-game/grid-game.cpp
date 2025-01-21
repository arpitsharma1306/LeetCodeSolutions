class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long>PreL(n+1,0);
        vector<long long>PreR(n+1,0);
        PreL[0]=grid[1][0];
        for(int i=1;i<n;i++){
            PreL[i]=(PreL[i-1]+grid[1][i]);
        }
        PreR[n-1]=grid[0][n-1];
        for(int i=n-2;i>=0;i--){
            PreR[i]=(PreR[i+1]+grid[0][i]);
        }

        int l=0,r=n-1;
        while(l<r){
            if(PreL[l]<=PreR[r]){
                l++;
            }else{
                r--;
            }
        }

        for(int i=0;i<=l;i++){
            grid[0][i]=0;
        }
        for(int i=l;i<n;i++){
            grid[1][i]=0;
        }

        long long sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1+=grid[0][i];
            sum2+=grid[1][i];
        }

        if(sum1>sum2) return sum1;

        return sum2;

    }
};