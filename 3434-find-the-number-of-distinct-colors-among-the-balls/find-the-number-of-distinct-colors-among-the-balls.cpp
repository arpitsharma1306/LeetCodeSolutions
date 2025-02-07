class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int>result(n);
        unordered_map<int,int>colors;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int ball=queries[i][0];
            int color=queries[i][1];
            if(mp.find(ball)!=mp.end()){
                int prev_color=mp[ball];
                colors[prev_color]--;
                if(colors[prev_color]==0){
                    colors.erase(prev_color);
                }
                mp[ball]=color;
                colors[color]++;
                result[i]= colors.size();
            }else{
                mp[ball]=color;
                colors[color]++;
                result[i]= colors.size();
            }
        }

        return result;
    }
};