class Solution {
public:
    const int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>delays(delay,0);
        vector<int>forgets(forget,0);
        long long count = 1;
        long long active = 0;
        delays[0] = 1;
        forgets[0] = 1; 
        for(int i=1;i<n;i++){
            active = (active + delays[delay-1])%mod;
            active = (active - forgets[forget-1] + mod)%mod;
            count = (count + active)%mod;
            count = (count - forgets[forget-1] + mod)%mod;
            for(int i=delay-1;i>0;i--){
                delays[i]=delays[i-1];
            }
            delays[0]=active;
            for(int i=forget-1;i>0;i--){
                forgets[i]=forgets[i-1];
            }
            forgets[0]=active;
        }

        return count;
    }
};