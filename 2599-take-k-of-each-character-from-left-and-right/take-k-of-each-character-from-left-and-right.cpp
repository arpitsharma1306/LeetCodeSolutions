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
        int requiredA = a - k, requiredB = b - k, requiredC = c - k;
        while(j<n){
            if(s[j]=='a') requiredA--;
            else if(s[j]=='b') requiredB--;
            else if(s[j]=='c') requiredC--;
            while(requiredA < 0 || requiredB < 0 || requiredC < 0){
                if(s[i]=='a') requiredA++;
                else if(s[i]=='b') requiredB++;
                else if(s[i]=='c') requiredC++;
                i++;
            }
            
            maxLen=max(maxLen,j-i+1);
            j++;
        }

        return n-maxLen;
    }
};