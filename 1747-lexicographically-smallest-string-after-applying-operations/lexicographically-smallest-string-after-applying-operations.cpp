class Solution {
public:
    unordered_set<string>st;
    void adding(string node,int a,queue<string>&q){
        for(int i=1;i<node.size();i+=2){
            int digit = node[i]-'0';
            int new_digit = (digit+a)%10;
            node[i] = ('0'+new_digit);
        }
        if(st.find(node)==st.end()){
            q.push(node);
            st.insert(node);
        }
    }

    void rotating(string s,int b,queue<string>&q){
        int n = s.size();
        b = b % n; 
        string new_s  = s.substr(n - b) + s.substr(0, n - b);
        if(st.find(new_s)==st.end()){
            q.push(new_s);
            st.insert(new_s);
        }
    }
    string findLexSmallestString(string s, int a, int b) {
        
        string res = s;
        queue<string>q;
        q.push(s);
        st.insert(s);
        while(!q.empty()){
            string node = q.front();
            q.pop();
            res = min(res,node);
            adding(node,a,q);
            rotating(node,b,q);
        }

        return res;
    }
};