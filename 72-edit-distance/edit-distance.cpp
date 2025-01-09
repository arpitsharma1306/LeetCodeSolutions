class Solution {
public:
    int t[501][501];
    int solve(string &word1,string &word2,int i,int j){
        if(i>=word1.size()){
            return word2.size()-j;
        }
        if(j>=word2.size()){
            return word1.size()-i;
        }

        if(t[i][j]!=-1) return t[i][j];

        if(word1[i]==word2[j]){
            return t[i][j]=solve(word1,word2,i+1,j+1);
        }

        int insertion = 1 + solve(word1,word2,i,j+1);
        int deletion  = 1 + solve(word1,word2,i+1,j);
        int replaced  = 1 + solve(word1,word2,i+1,j+1);

        return t[i][j] = min({insertion,deletion,replaced});
    }
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        return solve(word1,word2,0,0);
    }
};