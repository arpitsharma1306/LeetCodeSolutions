class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(j==m) break;
            char ch=(str1[i]-'a'+1)%26 + 'a';
            if((str1[i]==str2[j]) || (ch==str2[j])){
                j++;
            }
        }

        if(j==m) return true;

        return false;
    }
};