class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        map<pair<char,int>,int>mp;

        for(int i=0;i<n;i++){
            char ch=s[i];
            int len=0;
            for(int j=i;j<n;j++){
                if(s[j]==ch){
                    len++;
                    mp[{ch,len}]++;
                }else{
                    break;
                }
            }
        }

        int result=0;
        for(auto& it:mp){
            int len=it.first.second;
            int repeat=it.second;
            if(repeat>=3 && len>result){
                result=len;
            }
        }

        return result==0?-1:result;
    }
};