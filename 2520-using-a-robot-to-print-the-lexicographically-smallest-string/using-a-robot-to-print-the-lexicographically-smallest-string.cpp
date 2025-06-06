class Solution {
public:
    char solve(vector<int>&freq){
        for(int i=0;i<26;i++){
            if(freq[i]) return 'a'+i;
        }

        return 'a';
    }
    string robotWithString(string s) {
        stack<char>st;
        string t="";
        vector<int>freq(26,0);
        for(char& ch:s){
            freq[ch-'a']++;
        }

        for(char &ch:s){
            st.push(ch);
            freq[ch-'a']--;

            while(!st.empty() && st.top()<=solve(freq)){
                t+=st.top();
                st.pop();
            }
        }

        while(!st.empty()){
            t+=st.top();
            st.pop();
        }

        return t;
    }
};