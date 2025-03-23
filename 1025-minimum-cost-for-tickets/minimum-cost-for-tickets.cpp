class Solution {
public:
    vector<int>t;
    int solve(vector<int>& days, vector<int>& costs,int n,int idx){
        if(idx>=n){
            return 0;
        }

        if(t[idx]!=-1){
            return t[idx];
        }

        int curr_day=days[idx];
        int day_pass = costs[0] + solve(days,costs,n,idx+1);

        int week_idx = idx;
        while(week_idx<n && curr_day+6>=days[week_idx]){
            week_idx++;
        }
        int week_pass = costs[1] + solve(days,costs,n,week_idx);

        int month_idx = idx;
        while(month_idx<n && curr_day+29>=days[month_idx]){
            month_idx++;
        }
        int month_pass = costs[2] + solve(days,costs,n,month_idx);

        return t[idx] = min({day_pass,week_pass,month_pass});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        t.resize(n+1,-1);
        int minCost = solve(days,costs,n,0);

        return minCost;
    }
};