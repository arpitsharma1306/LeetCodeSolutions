class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        int a=0,b=0,c=0;
        for(char ch:s){
            if(ch=='a') a++;
            else if(ch=='b') b++;
            else if(ch=='c') c++;
        }

        if(a<k || b<k || c<k) return -1;

        int i=0,j=0,maxLen=0;
        while(j<n){
            if(s[j]=='a') a--;
            else if(s[j]=='b') b--;
            else if(s[j]=='c') c--;
            while(i<=j && (a<k || b<k || c<k)){
                if(s[i]=='a') a++;
                else if(s[i]=='b') b++;
                else if(s[i]=='c') c++;
                i++;
            }
            
            maxLen=max(maxLen,j-i+1);
            j++;
        }

        return n-maxLen;
    }
};