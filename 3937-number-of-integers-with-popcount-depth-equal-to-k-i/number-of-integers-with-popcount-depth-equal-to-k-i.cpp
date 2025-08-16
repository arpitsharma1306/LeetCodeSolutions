class Solution {
public:

    long long dp[65][65][2];

    long long solve(int idx,int ones,bool tight,int target,string &s){
        if(ones>target){
            return 0;
        }
        if(idx==s.size()){
            return ones==target?1:0;
        }

        if(dp[idx][ones][tight]!=-1) return dp[idx][ones][tight];

        long long res = 0;
        int limit = tight?(s[idx]-'0'):1;

        for(int d=0;d<=limit;d++){
            bool new_tight = tight && (d==limit);
            res += solve(idx+1,ones+d,new_tight,target,s);
        }

        return dp[idx][ones][tight] = res;
    }

    long long popcountDepth(long long n, int k) {
        if(k==0) return 1;
        vector<int> v(65, 0);

        for (int j = 1; j < 65; j++) {
            int depth = 0;
            int x = j;  // work with a copy

            while (x > 1) {
                int count = 0;
                for (int i = 0; i < 64; i++) {
                    if (x & (1LL << i)) count++;
                }
                depth++;
                x = count;
            }

            v[j] = depth;  // store result for j
        }

        string s = "";
        while(n>0){
            s += (n%2) + '0';
            n/=2;
        }
        reverse(s.begin(),s.end());

        long long total = 0;
        for(int ones = 1;ones<=64;ones++){
            if(v[ones]==k-1){
                memset(dp,-1,sizeof(dp));
                total+= solve(0,0,true,ones,s);

                if(k==1) total-=1;
            }
        }

        return total;
    }
};