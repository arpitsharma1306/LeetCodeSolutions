class Solution {
public:
    vector<vector<int>>t;
    int solve(vector<int>& cuts,int l,int r){
        if(r-l<2){
            return t[l][r] = 0;
        }
        if(t[l][r]!=-1){
            return t[l][r];
        }
        int result = INT_MAX;
        
        for(int idx=l+1;idx<r;idx++){
            int cost = (cuts[r]-cuts[l]) + solve(cuts,l,idx) + solve(cuts,idx,r);
            result = min(result,cost);
        }

        return t[l][r] = result;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int sz=cuts.size();
        t.resize(sz+1,vector<int>(sz+1,-1));
        return solve(cuts,0,cuts.size()-1);

    }
};