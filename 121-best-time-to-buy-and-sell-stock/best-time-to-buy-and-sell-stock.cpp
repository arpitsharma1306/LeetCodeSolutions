class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        stack<int>st;
        vector<int>GRE(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<prices[i]){
                st.pop();
            }
            if(!st.empty())GRE[i]=st.top();

            if(st.empty()) st.push(prices[i]); 
        }

        int maxProfit=0;
        for(int i=0;i<n;i++){
            if(GRE[i]!=-1){
                int profit=GRE[i]-prices[i];
                maxProfit=max(maxProfit,profit);
            }
        }

        return maxProfit;
    }
};