class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2==1) return false;

        int open=0,close=0,card=0;

        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                card++;
                continue;
            }
            if(s[i]=='(') open++;
            else if(s[i]==')') close++;

            if(close>open && card>0){
                card--;
                open++;
            }else if(close>open && card<=0){
                return false;
            }
        }

        open=0,close=0,card=0;

        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0'){
                card++;
                continue;
            }
            if(s[i]=='(') open++;
            else if(s[i]==')') close++;

            if(open>close && card>0){
                card--;
                close++;
            }else if(open>close && card<=0){
                return false;
            }
        }

        return true;
    }
};