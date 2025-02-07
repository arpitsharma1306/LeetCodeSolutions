class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>ctp; //capital,profit
        for(int i=0;i<n;i++){
            ctp.push_back({capital[i],profits[i]});
        }
        sort(begin(ctp),end(ctp));
        priority_queue<int>pq;
        int maxProfit=w;
        int i=0;
        while(k>0 && i<n){
            while(i<n && ctp[i].first<=w){
                pq.push(ctp[i].second);
                i++;
            }
            if(pq.empty()) return maxProfit;
            maxProfit+=pq.top();
            w+=pq.top();
            pq.pop();
            k--;
        }

        while(k>0 && !pq.empty()){
            maxProfit+=pq.top();
            pq.pop();
            k--;
        }

        return maxProfit;
    }
};