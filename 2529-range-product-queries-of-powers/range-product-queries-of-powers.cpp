class Solution {
public:
    const long long mod = 1000000007LL;
    void preCompute(int n,vector<long long>&powers){
        long long i=1;
        while(i<n){
            i*=2;
        }
        if(i>n) i/=2;
        
        if(i==n){
            powers.push_back(i);
            return;
        } 
        
        while(n>0){
            while(i>n){
                i/=2;
            }
            n-=i;
            powers.push_back(i); 
        }

        sort(powers.begin(),powers.end());
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long>powers;
        preCompute(n,powers);
        int m=powers.size();
        
        vector<int>ans;
        // vector<long long>prod(m);
        // prod[0]=powers[0];
        // for(int i=1;i<m;i++){
        //     prod[i] = prod[i-1]*powers[i];
        // }
        // for(auto &q:queries){
        //     int left=q[0]-1, right=q[1];
        //     if(left<0){
        //         ans.push_back(prod[right]);
        //     }else{
        //         long long res = (prod[right]/prod[left])%mod;
        //         ans.push_back(res);
        //     }
        // }

        for(auto& q:queries){
            int left=q[0], right=q[1];
            long long res = 1;
            for(int i=left;i<=right;i++){
                res = (res*powers[i])%mod;
            }
            ans.push_back(res);
        }
    
        return ans;
    }
};