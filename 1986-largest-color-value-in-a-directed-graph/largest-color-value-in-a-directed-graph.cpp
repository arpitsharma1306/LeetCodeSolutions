class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int>q;
        vector<vector<int>>t(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                t[i][colors[i]-'a']=1;
            } 
        }

        int countNodes=0,result=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            countNodes++;
            result=max(result,t[u][colors[u]-'a']);

            for(auto& v:adj[u]){
                for(int i=0;i<26;i++){
                    t[v][i] = max(t[v][i], t[u][i] + (i==colors[v]-'a'));
                }
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        if(countNodes<n) return -1;

        return result;
    }
};