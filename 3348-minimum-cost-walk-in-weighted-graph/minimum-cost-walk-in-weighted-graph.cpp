class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }

        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        parent[y]=x;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        vector<int>cost(n,-1);
        for(auto& edge:edges){
            int u=edge[0],v=edge[1],w=edge[2];
            int parent_u=find(u);
            int parent_v=find(v);
            if(parent_u!=parent_v){
                Union(parent_u,parent_v);
                cost[parent_u] &= cost[parent_v];
            }

            cost[parent_u] &= w; 
        }
        vector<int>result;
        for(auto&q :query){
            int s=q[0],e=q[1];
            int parent_s=find(s),parent_e=find(e);
            if(parent_s!=parent_e){
                result.push_back(-1);
            }
            else{
                int costing=cost[parent_s];
                result.push_back(costing);
            }
        }

        return result;
    }
};