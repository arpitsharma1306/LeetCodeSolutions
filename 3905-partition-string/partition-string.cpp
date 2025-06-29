class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string>result;
        unordered_map<string,int>mp;
        int n=s.size();
        int i=0;
        string ans="";
        while(i<n){
            ans.push_back(s[i]);
            if(mp.count(ans)){
                i++;
            }
            else{
                result.push_back(ans);
                mp[ans]++;
                ans="";
                i++;
            }
        }
        return result;
    }
};