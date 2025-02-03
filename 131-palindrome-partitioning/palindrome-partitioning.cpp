class Solution {
public:
    int n;
    bool isPalindrome(string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;

            l++;
            r--;
        }

        return true;
    }
    void backtrack(string &s,int idx,vector<string>curr,vector<vector<string>>&answer){
        if(idx>=n){
            answer.push_back(curr);
            return;
        }

        for(int i=idx;i<n;i++){
            if(isPalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                backtrack(s,i+1,curr,answer);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<vector<string>> answer;
        vector<string>curr;

        backtrack(s,0,curr,answer);

        return answer;
    }
};