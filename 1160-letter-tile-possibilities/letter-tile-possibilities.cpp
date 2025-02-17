class Solution {
public:
    void DFS(vector<int>freq,unordered_set<string>&st,int n,int i,string s){
        if(i>=n){
            if(st.find(s)==st.end()){
                st.insert(s);
                return;
            }
        }
        for(int j=0;j<26;j++){
            vector<int>freq_at = freq;
            string s_=s;
            if(freq_at[j]>0){
                freq_at[j]--;
                char ch='A'+j;
                s_+=ch;
                DFS(freq_at,st,n,i+1,s_);
            }
        }
        return;
    }
    void solve(string& tiles,int n,unordered_set<string>&st){
        vector<int>freq(26,0);

        for(int i=0;i<n;i++){
            freq[tiles[i]-'A']++;
        }
        for(int i=1;i<=n;i++){
            string s;
            DFS(freq,st,i,0,s);
        }
    }
    int numTilePossibilities(string tiles) {
        int n=tiles.length();
        unordered_set<string>st;
        string s="";
        solve(tiles,n,st);

        for(auto ch:st){
            cout<<ch<<" ";
        }

        return st.size();
    }
};