class Solution {
public:
    int diameter(vector<vector<int>>&paths,vector<bool>&visited,int curr,int &d){
        visited[curr] = true;
        int max1=0,max2=0;
        for(int &p:paths[curr]){
            if(!visited[p]){
                int depth=diameter(paths,visited,p,d);
                if(depth>=max1){
                    max2=max1;
                    max1=depth;
                }
                else if(depth>max2) max2=depth; 
            }
        }

        //diameter of curr node is max1+max2
        d=max(d,max1+max2);
        return max(max1,max2)+1;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1=0,d2=0,n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>>paths(n);
        for(auto &vec:edges1){
            paths[vec[0]].push_back(vec[1]);
            paths[vec[1]].push_back(vec[0]);
        }
        vector<bool>visited(n,false);
        diameter(paths,visited,0,d1);

        paths = vector<vector<int>> (m);
        for(auto &vec:edges2){
            paths[vec[0]].push_back(vec[1]);
            paths[vec[1]].push_back(vec[0]);
        }
        visited = vector<bool>(m,false);
        diameter(paths,visited,0,d2);

        int d3 = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d3,d1,d2});
    }
};