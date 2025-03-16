class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n) , answer(n);
        vector<int>indegree(n,0);
        for(auto edge:edges){
            int parent=edge[0],child=edge[1];
            adj[parent].push_back(child);
            indegree[child]++;
        }

        queue<int>q;
        vector<set<int>>ancestors(n);
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }


        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int child:adj[node]){
                ancestors[child].insert(node);
                ancestors[child].insert(ancestors[node].begin(),ancestors[node].end());

                if(--indegree[child]==0){
                    q.push(child);
                }
            }
        }

        for(int i=0;i<n;i++){
            answer[i] = vector<int>(ancestors[i].begin(),ancestors[i].end());
        }

        return answer;
    }
};