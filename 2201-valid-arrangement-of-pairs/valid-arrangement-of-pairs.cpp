class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //build adjacency list - Graph
        unordered_map<int,vector<int>>adj;
        //build indegree and outdegree list
        //key-node, value-indegree and outdegree
        unordered_map<int,int>indeg;
        unordered_map<int,int>outdeg;

        for(auto& pair:pairs){
            int u=pair[0],v=pair[1];
            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }

        // find start node of euler's path. cond: outdegree-indegree==1
        int startnode=pairs[0][0];
        for(auto& it:adj){
            int node=it.first;
            if(outdeg[node]-indeg[node]==1){
                startnode=node;
                break;
            }
        }

        //DFS
        vector<int>path; //store eulers path
        stack<int>st;
        st.push(startnode);
        while(!st.empty()){
            int curr=st.top();
            if(!adj[curr].empty()){
                int neigh=adj[curr].back();
                adj[curr].pop_back();
                st.push(neigh);
            }else{
                path.push_back(st.top());
                st.pop();
            }
        }

        //build your result
        reverse(begin(path),end(path));
        vector<vector<int>>result;
        for(int i=0;i<path.size()-1;i++){
            result.push_back({path[i],path[i+1]});
        }

        return result;
    }
};