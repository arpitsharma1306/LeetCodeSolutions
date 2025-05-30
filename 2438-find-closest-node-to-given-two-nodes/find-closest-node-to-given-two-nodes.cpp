class Solution {
public:
    void dfs(vector<int>& edges, vector<bool>& vis, vector<int>& dist, int node, int cnt) {
        dist[node] = cnt;
        vis[node] = true;

        int neighbor = edges[node];
        if (neighbor != -1 && !vis[neighbor]) {
            dfs(edges, vis, dist, neighbor, cnt + 1);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size()+1;
        // unordered_map<int,int>adj(n);
        // for(int i=0;i<n-1;i++){
        //     if(edges[i]==-1) continue;
        //     adj[i].push_back(edges[i]);
        // }

        vector<int>dist1(n,-1);
        vector<int>dist2(n,-1);
        vector<bool>vis(n,false);
        dfs(edges,vis,dist1,node1,0);
        fill(vis.begin(), vis.end(), false);
        dfs(edges,vis,dist2,node2,0);

        int minD=INT_MAX;
        int minNode=-1;
        for(int i=0;i<n;i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                if(max(dist1[i],dist2[i])<minD){
                    minD=max(dist1[i],dist2[i]);
                    minNode=i;
                }
            }
        }

        return minNode;
    }
};