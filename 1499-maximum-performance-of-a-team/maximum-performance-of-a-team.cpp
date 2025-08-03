class Solution {
public:
    const int mod = (int)1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long tot_speed = 0, ans = 0;
        for(int i=0;i<n;i++){
            if(pq.size()==k){
                tot_speed -= pq.top();
                pq.pop();
            }
            tot_speed += v[i].second;
            pq.push(v[i].second); 
            ans = max(ans,tot_speed*v[i].first);
        }
        return ans%mod;
        
    }
};