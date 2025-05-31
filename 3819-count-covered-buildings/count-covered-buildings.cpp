class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>>x(n+1);
        vector<vector<int>>y(n+1);

        for(auto &build:buildings){
            x[build[0]].push_back(build[1]);
            y[build[1]].push_back(build[0]);
        }

        for(auto& y_vec:x){
            sort(begin(y_vec),end(y_vec));
        }
        for(auto& x_vec:y){
            sort(begin(x_vec),end(x_vec));
        }

        int cnt=0;

        for(auto& build:buildings){
            if(x[build[0]].size()<3 || y[build[1]].size()<3) continue;

            int low_y=x[build[0]][0], high_y=x[build[0]][x[build[0]].size()-1];
            int low_x=y[build[1]][0], high_x=y[build[1]][y[build[1]].size()-1];

            if(low_x<build[0] && build[0]<high_x && low_y<build[1] && build[1]<high_y){
                cnt++;
            }
        }

        return cnt;

    }
};