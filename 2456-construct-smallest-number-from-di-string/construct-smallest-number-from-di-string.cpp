class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        string ans="";
        int stack[n+1];
        int index=0;

        for(int i=0;i<=n;i++){
            stack[index++]=i+1;
            if(i==n || pattern[i]=='I'){
                while(index>0){
                    ans+= to_string(stack[--index]);
                }
            }
        }

        return ans;
    }
};