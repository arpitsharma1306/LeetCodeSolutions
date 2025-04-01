class Solution {
public:
    int n;
    vector<long long>t;
    long long solve(vector<vector<int>>& questions,int curr){
        if(curr>=n){
            return 0;
        }
        if(t[curr]!=-1) return t[curr];

        long long taken = questions[curr][0] + solve(questions,curr+questions[curr][1]+1);
        long long skip = solve(questions,curr+1);

        return t[curr] = max(taken,skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        t.resize(n+1,-1);
        return solve(questions,0);
    }
};