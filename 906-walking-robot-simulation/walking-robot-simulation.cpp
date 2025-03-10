class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>st;
        for(vector<int>obs:obstacles){
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int maxD=0,x=0,y=0;
        pair<int,int>dir = {0,1}; //for north direction

        for(int i=0;i<commands.size();i++){
            if(commands[i]==-2){ //left turn
                dir = {-dir.second,dir.first};
            }
            else if(commands[i]==-1){ //right turn
                dir = {dir.second,-dir.first};
            }else{
                for(int steps=0;steps<commands[i];steps++){
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    string keyValue=to_string(newX)+"_"+to_string(newY);
                    if(st.find(keyValue)!=st.end()){
                        break;
                    }
                    x=newX,y=newY;
                }
            }
            maxD = max(maxD,x*x+y*y);
        }

        return maxD;
    }
};