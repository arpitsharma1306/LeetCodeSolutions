class Solution {
public:
    string resultingString(string s) {
        string result="";
        int i=0;
        int n=s.size();
        while(i<n){
            if(result.size()==0){
                result+=s[i];
                i++;
                continue;
            }

            if(abs(result.back()-s[i])%24==1){
                result.pop_back();
            }else{
                result+=s[i];
            }
            i++;
        }

        return result;
    }
};