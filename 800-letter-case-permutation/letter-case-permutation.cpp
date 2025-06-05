class Solution {
public:
    vector<string>result;
    void solve(string& s,string temp){
        if(temp.size()==s.size()){
            result.push_back(temp);
            return;
        }

        char ch = s[temp.size()];
        if(ch>='a' && ch<='z'){
            char cap=toupper(ch);
            solve(s,temp+ch);
            solve(s,temp+cap);
        }else{
            solve(s,temp+ch);
        }
    }
    vector<string> letterCasePermutation(string s) {
        for(char& ch:s){
            ch = tolower(ch);
        }

        solve(s,"");

        return result;
    }
};