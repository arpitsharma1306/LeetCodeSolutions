class Solution {
public:
    bool isPossible(vector<int>& ranks, long long cars,long long time){
        int n=ranks.size();
        long long cnt=0;

        for(int i=0;i<n;i++){
            long long cars_repair = sqrt(time/ranks[i]);
            cnt+=cars_repair;

            if(cnt>=cars) return true;
        }

        return false;
    }
    long long repairCars(vector<int>& ranks, long long cars) {
        int n=ranks.size();
        long long min_rank = *min_element(begin(ranks),end(ranks));
        long long low = 1;
        long long high = min_rank*cars*cars;
        long long ans=high;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(isPossible(ranks,cars,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;
    }
};