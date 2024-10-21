class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int content=0;

        sort(begin(g),end(g));
        sort(begin(s),end(s));

        int i=0,j=0;

        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                content++;
                i++;
                j++;
            }
            else if(g[i]>s[j]){
                j++;
            }
        }

        return content;
    }
};