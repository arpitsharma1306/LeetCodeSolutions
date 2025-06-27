class Solution {
public:
    bool helper(string str,string t,int k){
        int count=0,i=0;
        for(char& ch:t){
            if(ch==str[i]){
                if(++i==str.size()){
                    if(++count==k) return true;
                    i=0;
                }
            }
        }
        return false;
        
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        string result = "";
        queue<string>q;
        q.push("");
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            for(char ch='a';ch<='z';ch++){
                string temp = curr+ch;
                if(helper(temp,s,k)){
                    q.push(temp);
                    result = temp;
                }
            }
        }

        return result;

    }
};