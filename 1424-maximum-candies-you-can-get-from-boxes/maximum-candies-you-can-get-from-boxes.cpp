class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=candies.size();
        int total = 0;
        queue<int>q;
        unordered_set<int>close;
        unordered_set<int>avail_keys;
        for(auto& idx:initialBoxes){
            if(status[idx]==1) q.push(idx);
            else close.insert(idx);

            for(auto &key:keys[idx]){
                avail_keys.insert(key);
            }
        }

        while(!q.empty()){
            int box = q.front();
            q.pop();
            total += candies[box];

            for(auto &key:keys[box]){
                avail_keys.insert(key);
            }

            for(auto &it:containedBoxes[box]){
                if(status[it]==1){
                    q.push(it);
                } 
                else if(status[it]==0 && avail_keys.find(it)!=avail_keys.end()){
                    q.push(it);
                    status[it]=1;
                }
                else{
                    close.insert(it);
                }
            }

            for(auto& it:close){
                if(status[it]==0 && avail_keys.find(it)!=avail_keys.end()){
                    status[it]=1;
                    q.push(it);
                }
            }
        }


        return total;

    }
};