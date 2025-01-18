class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<int>left(n),right(n);

        left[0]=0;
        int minL=prices[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],prices[i]-minL);
            if(prices[i]<minL) minL=prices[i];
        }

        right[n-1]=0;
        int maxR=prices[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],maxR-prices[i]);
            if(prices[i]>maxR) maxR=prices[i];
        }

        int maxProfit=right[0];
        for(int i=0;i<n-1;i++){
            maxProfit=max(maxProfit,left[i]+right[i+1]);
        }

        return maxProfit;
    }
};