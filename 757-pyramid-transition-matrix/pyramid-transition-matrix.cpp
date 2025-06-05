class Solution {
public:
    bool solve(int idx,string temp,string bottom,unordered_map<string,vector<char>>&mp,unordered_map<string,bool>&memo){
        if(bottom.size()==1) return true;

        if(idx==bottom.size()-1){
            if(memo.count(temp)){
                return memo[temp];
            }else{
                bool res = solve(0,"",temp,mp,memo);
                return memo[temp]=res;
            }
        }

        string two_ch = bottom.substr(idx,2);
        for(char& ch:mp[two_ch]){
            if(solve(idx+1,temp+ch,bottom,mp,memo)) return true;
        }

        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>>mp;
        for(string& s:allowed){
            mp[s.substr(0,2)].push_back(s[2]);
        }
        unordered_map<string,bool>memo;

        return solve(0,"",bottom,mp,memo);
    }
};