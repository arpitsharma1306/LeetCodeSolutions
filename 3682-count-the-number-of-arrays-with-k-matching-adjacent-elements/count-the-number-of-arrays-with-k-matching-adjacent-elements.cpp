class Solution {
public:
    using ll = long long;
    int MOD = 1e9+7;
    vector<int> fact, invfact;

    int binaryexp(ll a,ll b){
        ll result = 1;
        while(b){
            if(b&1){
                result = (result*a)%MOD;
            }
            a = (a*a) % MOD;
            b/=2;
        }

        return result;
    }

    int MMI(int val){
        return binaryexp(val,MOD-2);
    }

    void inverseFact(const int& n){
        invfact = vector<int>(n+1);
        invfact[n] = MMI(fact[n]);
        for(int i=n;i>0;i--){
            invfact[i-1] = (1LL*invfact[i]*i)%MOD;
        }
    }
    void factorial(const int &n){
        fact = vector<int>(n+1);
        fact[0]=1;
        for(int i=1;i<=n;i++){
            fact[i] = (1LL * fact[i-1] * i)%MOD; 
        }
    }
    int countGoodArrays(int n, int m, int k) {
        factorial(n);
        inverseFact(n);

        int run_ways = (1LL * fact[n-1] * invfact[n-k-1]%MOD * invfact[k])%MOD;
        int ways_to_assign = (1LL * m * binaryexp(m-1,n-k-1))%MOD;
        return (1LL * run_ways * ways_to_assign)%MOD; 
    }
};