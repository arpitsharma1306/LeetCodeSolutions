class Solution {
public:
    vector<vector<double>>t;
    vector<pair<int,int>> serves = {{100,0},{75,25},{50,50},{25,75}};
    double solve(double A, double B){
        if(A<=0 && B<=0){
            return 0.5;
        }
        if(A<=0) return 1;
        if(B<=0) return 0.0;

        if(t[A][B]!=-1.0){
            return t[A][B];
        }
        double prob=0.0;
        for(auto P:serves){
            double A_taken=P.first;
            double B_taken=P.second;
            prob += solve(A-A_taken,B-B_taken);
        }

        return t[A][B]=0.25*prob;
    }
    double soupServings(int n) {
        if(n>=4300) return 1;
        t.resize(n+1,vector<double>(n+1,-1.0));
        return solve(n,n);
    }
};