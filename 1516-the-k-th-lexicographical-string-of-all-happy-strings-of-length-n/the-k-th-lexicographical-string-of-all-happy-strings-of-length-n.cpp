class Solution {
public:
    string ans;
    void solve(int len,int n,int& cnt,vector<char>&v,string& s){
        if(len==n){
            if(--cnt==0){
                ans=s;
            }
            return;
        }

        for(int i=0;i<3;i++){
            if(len==0 || v[i]!=s.back()){
                s.push_back(v[i]);
                solve(len+1,n,cnt,v,s);
                s.pop_back();
                if(cnt==0) return;
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<char>v = {'a','b','c'};
        ans="";
        string s="";
        solve(0,n,k,v,s);
        return ans;
    }
};