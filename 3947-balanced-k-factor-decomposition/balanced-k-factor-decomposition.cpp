class Solution {
public:
    vector<vector<int>>ways;
    void solve(int n,vector<int>v,int k,int x){
        if(k==0){
            if(n==1){
                ways.push_back(v);
            }
            return;
        }

        if(n<=1) return;

        for(int i=x;i<=n/2;i++){
            if(n%i==0){
                v.push_back(i);
                solve(n/i,v,k-1,i);
                v.pop_back();
            }
        }

        if(k==1){
            v.push_back(n);
            ways.push_back(v);
        }
        return;
    }
    vector<int> minDifference(int n, int k) {
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                vector<int>v;
                v.push_back(i);
                solve(n/i,v,k-1,i);
                v.pop_back();
            }
        }
        vector<int>ans;
        int min_diff=INT_MAX;
        for(auto &v:ways){   
            int s = *min_element(v.begin(),v.end()); 
            int e = *max_element(v.begin(),v.end());
            if(min_diff>abs(e-s)){
                min_diff=abs(e-s);
                ans = v;
            }
        }

        return ans;

    }
};