class Solution {
public:
    int n;
    vector<vector<int>>t;
    int solve(string& s,int i,int prev){
        if(i>=n) return 0;

        if(t[i][prev]!=-1) return t[i][prev];

        int flip=INT_MAX, noflip=INT_MAX;
        if(s[i]=='0'){
            if(prev==0){
                flip = 1 + solve(s,i+1,1);
                noflip= solve(s,i+1,0);
            }else{
                flip = 1 + solve(s,i+1,1);
            }
        }else{
            if(prev==0){
                flip = 1 + solve(s,i+1,0);
                noflip = solve(s,i+1,1);
            }else{
                noflip = solve(s,i+1,1);
            }
        }
        
        return t[i][prev] = min(flip,noflip);
    }
    int minFlipsMonoIncr(string s) {
        n=s.size();
        t.resize(n+1,vector<int>(2,-1));
        return solve(s,0,0);
    }
};