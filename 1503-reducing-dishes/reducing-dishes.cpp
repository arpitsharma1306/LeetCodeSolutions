class Solution {
public:
    vector<vector<int>>t;
    int n, maxi;
    int solve(vector<int>& sat,int i,int multi){
        if(i>=n){
            return 0;
        }
        if(t[i][multi]!=-1) return t[i][multi];
        int taken = sat[i]*multi + solve(sat,i+1,multi+1);
        int skip = solve(sat,i+1,multi);

        return t[i][multi] = max(taken,skip); 
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n=satisfaction.size();
        t.resize(n,vector<int>(n+1,-1));
        sort(begin(satisfaction),end(satisfaction));
        return solve(satisfaction,0,1);

    }
};