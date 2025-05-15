class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        int max_length=0;
        vector<string>ans;

        for(int i=0;i<n;i++){
            vector<string>temp;
            temp.push_back(words[i]);
            int len=1;
            int last_group=groups[i];
            for(int j=i+1;j<n;j++){
                if(last_group!=groups[j]){
                    len++;
                    last_group=groups[j];
                    temp.push_back(words[j]);
                }
            }
            if(max_length<len){
                max_length=len;
                ans = temp;
            }
        }

        return ans;
    }
};