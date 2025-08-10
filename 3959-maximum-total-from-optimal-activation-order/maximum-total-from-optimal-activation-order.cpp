class Solution {
public:
    static bool customCompare(const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first != b.first)
                return a.first < b.first; // increasing order for first
            return a.second > b.second;   // decreasing order for second
        }
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n=value.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({limit[i],value[i]});
        }
        

        sort(v.begin(),v.end(),customCompare);
        priority_queue<int,vector<int>,greater<>>pq;
        int active=0;
        long long ans = 0;

        for(int i=0;i<n;){
            if(active<v[i].first){
                ans = ans + (long long)(v[i].second);
                active++;
                pq.push(v[i].first);
                i++;
            }
            while(i<n && v[i].first<=active){
                i++;
            }
            while(!pq.empty() && active>=pq.top()){
                pq.pop();
                active--;
            }

        }

        return ans;

    }
};