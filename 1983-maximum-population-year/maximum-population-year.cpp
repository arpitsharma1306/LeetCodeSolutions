class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        vector<int>births(101,0);
        vector<int>deaths(101,0);

        for(auto dates:logs){
            int birth=dates[0];
            int death=dates[1];
            births[birth-2050+100]++;
            deaths[death-2050+100]++;
        }

        int max_alive=0;
        int alive=0;
        int idx=-1;

        for(int i=0;i<=100;i++){
            alive+=births[i];
            alive-=deaths[i];
            if(alive>max_alive){
                max_alive=alive;
                idx=i;
            }
        }

        return 1950+idx;
    }
};