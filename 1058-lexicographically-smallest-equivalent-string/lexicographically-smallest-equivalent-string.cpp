class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]==x) return x;

        return parent[x] = find(parent[x]);
    }
    void Union(int c1,int c2){
        int p1=find(c1);
        int p2=find(c2);

        if(p1==p2) return;

        if(p1<p2){
            parent[p2]=p1;
        }
        else parent[p1]=p2;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for(int i=0;i<26;i++) parent[i]=i;

        for(int i=0;i<s1.size();i++){
            Union(s1[i]-'a',s2[i]-'a');
        }

        for(int i=0;i<baseStr.size();i++){
            baseStr[i] = (char)(find(baseStr[i]-'a')+'a');
        }

        return baseStr;
    }
};