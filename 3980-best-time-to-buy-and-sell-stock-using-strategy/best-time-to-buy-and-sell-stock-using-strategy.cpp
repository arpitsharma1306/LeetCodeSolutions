class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        long long profit = 0;
        long long max_profit = 0;
        for(int i=0;i<n;i++){
            profit += (prices[i]*strategy[i]);
        }

        max_profit = profit;
        for(int i=0;i<k/2;i++){
            profit -= (prices[i]*strategy[i]);
        }
        for(int i=k/2;i<k;i++){
            if(strategy[i]==-1) profit -= (prices[i]*strategy[i]);
            if(strategy[i]!=1) profit += prices[i];
        }
        max_profit = max(max_profit,profit);
        cout<<profit<<" ";
        for(int i=0;i<n-k;i++){
            profit +=  (prices[i]*strategy[i]);
            cout<<profit<<" ";
            if(strategy[i+k]==-1) profit -= (prices[i+k]*strategy[i+k]);
            profit -= prices[i+k/2];
            if(strategy[i+k]!=1) profit += prices[i+k];
            cout<<profit<<" ";
            max_profit = max(max_profit,profit); 
        }

        return max_profit;
    }
};