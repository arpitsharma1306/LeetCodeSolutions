class Solution {
public:
    #define ll long long
    void calculateBits(vector<ll>& v,ll x){
        for(int i=0;i<=31;i++){
            if(x & (1<<i)){
                v[i]++;
            }
        }
    }

    int minOperations(vector<int>& nums, int target) {
        vector<ll>targetvec(32,0), v(32,0);
        calculateBits(targetvec,target);
        for(auto& num:nums){
            calculateBits(v,num);
        }

        int oper=0;
        for(int i=0;i<31;i++){
            if(i>0) v[i] += (v[i-1]/2);

            if(targetvec[i]){
                if(v[i]==0){
                    int j=i+1;
                    while(v[j]==0 && j<31) j++;

                    if(j==31) return -1;
                    oper += (j-i);
                    v[j]--;
                    j--;

                    while(j>=i){
                        v[j]++;
                        j--;
                    }
                    
                }
                v[i]--;
            }
        }

        return oper;
    }
};