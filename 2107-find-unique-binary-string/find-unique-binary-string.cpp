class Solution {
public:
    void solve(unordered_set<string>&st,string& ans,string& s,int n){
        if(s.size()==n){
            if(st.find(s)==st.end()){
                ans=s;
            }
            return;
        }

        for(int i=0;i<2;i++){
            if(!ans.empty()) return;
            char ch = i+'0';
            s.push_back(ch);
            solve(st,ans,s,n);
            s.pop_back();
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        unordered_set<string>st;
        for(auto &num:nums){
            st.insert(num);
        }

        string ans="";
        string s="";
        solve(st,ans,s,n);
        return ans;
    }
};