class Solution {
public:
    string removeOccurrences(string s, string part) {
        if(s.size()<part.size()) return s;
        int n=s.size();
        int m=part.size();
        string ans=s.substr(0,m-1);
        for(int i=m-1;i<n;i++){
            ans+=s[i];
            if(ans.length()>=m && ans.substr(ans.length() - m, m)==part){
                ans.resize(ans.length()-m);
            }
        }

        return ans;
    }
};