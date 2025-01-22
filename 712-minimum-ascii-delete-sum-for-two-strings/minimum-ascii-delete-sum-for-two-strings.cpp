class Solution {
public:
    int n1,n2;
    vector<vector<int>>t;
    int solve(int i,int j,string& s1,string& s2){
        if(i>=n1 && j>=n2){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i>=n1){
            return t[i][j] = s2[j] + solve(i,j+1,s1,s2);
        }
        if(j>=n2){
            return t[i][j] = s1[i] + solve(i+1,j,s1,s2);
        }
        if(s1[i]==s2[j]){
            return t[i][j] = solve(i+1,j+1,s1,s2);
        }

        int delete_i=s1[i]+solve(i+1,j,s1,s2);
        int delete_j=s2[j]+solve(i,j+1,s1,s2);

        return t[i][j] = min(delete_i,delete_j);
        
    }
    int minimumDeleteSum(string s1, string s2) {
        n1=s1.size();
        n2=s2.size();
        t.resize(n1+1,vector<int>(n2+1,-1));
        return solve(0,0,s1,s2);
    }
};