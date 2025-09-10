class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size();
        unordered_map<int,unordered_set<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<languages[i].size();j++){
                mp[languages[i][j]].insert(i+1);
            }
        }

        unordered_set<int>users;
        for(auto &fr : friendships){
            int u=fr[0], v=fr[1];
            bool talk=false;
            for(int &lang:languages[u-1]){
                if(mp[lang].find(v)!=mp[lang].end()){
                    talk=true;
                    break;
                }
            }

            if(!talk){
                users.insert(u);
                users.insert(v);
            }
        }

        vector<int>user;
        for(auto& st:users){
            user.push_back(st);
        }

        int mini = m;

        for(int i=1;i<=n;i++){
            int cnt = 0;
            for(int &u:user){
                if(mp[i].find(u)==mp[i].end()){
                    cnt++;
                }
            }

            if(cnt<mini) mini=cnt;
        }

        return mini;
    }
};