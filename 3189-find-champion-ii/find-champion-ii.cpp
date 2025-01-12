class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>parents(n,-1);

        for(auto& edge:edges){
            int parent=edge[0];
            int child=edge[1];
            parents[child]=parent;
        }

        int champion=-1;
        for(int i=0;i<n;i++){
            if(parents[i]==-1 && champion!=-1){
                return -1;
            }
            if(parents[i]==-1){
                champion=i;
            }
        }

        return champion;
    }
};