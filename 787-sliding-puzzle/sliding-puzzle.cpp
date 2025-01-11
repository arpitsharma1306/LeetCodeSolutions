class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                start+=to_string(board[i][j]);
            }
        }
        string target="123450";

        unordered_map<int,vector<int>>mp;
        mp[0]={1,3};
        mp[1]={0,2,4};
        mp[2]={1,5};
        mp[3]={0,4};
        mp[4]={3,1,5};
        mp[5]={4,2};

        queue<string>q;
        q.push(start);
        unordered_set<string>visited;
        visited.insert(start);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr==target){
                    return level;
                }
                int idxof0=curr.find('0');
                for(int swapIdx:mp[idxof0]){
                    string newState=curr;
                    swap(newState[swapIdx],newState[idxof0]);
                    if(visited.find(newState)==visited.end()){
                        visited.insert(newState);
                        q.push(newState);
                    }
                }
            }
            level++;
        }

        return -1;
    }
};