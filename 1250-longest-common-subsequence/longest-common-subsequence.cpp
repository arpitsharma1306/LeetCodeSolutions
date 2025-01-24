class Solution {
public:
    int m,n;
    vector<vector<int>>t;
    int solve(string& s1,string& s2,int i,int j){
        if(i>=m) return 0;
        if(j>=n) return 0;

        if(t[i][j]!=-1) return t[i][j];
        if(s1[i]==s2[j]){
            return t[i][j] = 1 + solve(s1,s2,i+1,j+1);
        }
        else{
            int i_for = solve(s1,s2,i+1,j);
            int j_for = solve(s1,s2,i,j+1);
            return t[i][j] = max(i_for,j_for);
        }

        return -1;
    }
    int longestCommonSubsequence(string text1, string text2) {
        m=text1.size(); n=text2.size();
        t.resize(m,vector<int>(n,-1));
        return solve(text1,text2,0,0);
    }
};