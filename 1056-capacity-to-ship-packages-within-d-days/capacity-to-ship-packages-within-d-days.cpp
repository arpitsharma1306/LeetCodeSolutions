class Solution {
public:
    bool isShipped(vector<int>& weights, int days,int capacity){
        int n = weights.size();
        int time = 1; 
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (sum + weights[i] > capacity) {
                time++;
                sum = 0;
            }
            sum += weights[i];
            if (time > days) return false;
        }

        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int r=accumulate(weights.begin(),weights.end(),0);
        int l=*max_element(weights.begin(),weights.end());
        int result=INT_MAX;
        
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(isShipped(weights,days,mid)){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return result;

    }
};