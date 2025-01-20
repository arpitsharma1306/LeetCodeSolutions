class Solution {
public:
    int t[301][11];
    int solve(vector<int>&jd,int n,int idx,int d){
        //base case
        if(d==1){
            int maxD=jd[idx];
            for(int i=idx;i<n;i++){
                maxD=max(maxD,jd[i]);
            }
            return maxD;
        }

        if(t[idx][d]!=-1){
            return t[idx][d];
        }
        int maxD=0;
        int finalResult=INT_MAX;
        // hum start kaha se kar rhe h. hum first day end n-d ke baad nhi kar sakte as each day ke liye minimum ek job honi chahiye
        for(int i=idx;i<=n-d;i++){
            maxD=max(maxD,jd[i]);
            int result = maxD + solve(jd,n,i+1,d-1);
            finalResult=min(finalResult,result);
        }

        return t[idx][d]=finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        memset(t,-1,sizeof(t));
        return solve(jobDifficulty,n,0,d);
    }
};