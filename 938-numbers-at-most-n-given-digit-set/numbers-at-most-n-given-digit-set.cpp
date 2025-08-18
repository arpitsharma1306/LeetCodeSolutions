class Solution {
public:
    int dp[11][2][2];
    int solve(int idx,bool tight,bool started,vector<string>&digits,string num){
        if(idx>=num.size()){
            return started;
        }

        if(dp[idx][tight][started]!=-1) return dp[idx][tight][started];

        int limit = tight?num[idx]-'0':9;
        int cnt = 0;
        if(!started) cnt += solve(idx+1,false,false,digits,num);
        for(string& digi:digits){
            int digit = stoi(digi);
            if(tight==false || (tight && digit<=limit)) cnt += solve(idx+1,tight && digit==limit,true, digits,num);
        }

        return dp[idx][tight][started] = cnt;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,true,false,digits,num);
    }
};