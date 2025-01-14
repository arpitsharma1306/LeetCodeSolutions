class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(j==m) break;
            if((str2[j]-str1[i]+26)%26<=1) j++;
        }

        if(j==m) return true;

        return false;
    }
};