class Solution {
public:
    void solve(int n,unordered_set<string>&result,string s,vector<string>&ans){
        if(s.length()==n && result.find(s)==result.end()){
            result.insert(s);
            ans.push_back(s);
            return;
        }

        if(s.empty()){
            string a1="a";
            string b1="b";
            string c1="c";
            solve(n,result,a1,ans);
            solve(n,result,b1,ans);
            solve(n,result,c1,ans);
        }else{
            if(s[s.size()-1]=='a'){
                s+='b';
                solve(n,result,s,ans);
                s.pop_back();
                s+='c';
                solve(n,result,s,ans);
                s.pop_back();
            }else if(s[s.size()-1]=='b'){
                s+='a';
                solve(n,result,s,ans);
                s.pop_back();
                s+='c';
                solve(n,result,s,ans);
                s.pop_back();
            }else if(s[s.size()-1]=='c'){
                s+='b';
                solve(n,result,s,ans);
                s.pop_back();
                s+='a';
                solve(n,result,s,ans);
                s.pop_back();
            }
        }
        return;
    }
    string getHappyString(int n, int k) {
        unordered_set<string>result;
        vector<string>ans;
        string s="";
        solve(n,result,s,ans);
        sort(begin(ans),end(ans));

        if(ans.size()<k) return "";

        return ans[k-1];
    }
};