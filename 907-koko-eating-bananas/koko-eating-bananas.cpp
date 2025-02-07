class Solution {
public:
    int n;
    bool isPossible(vector<int>& piles,int speed,int h){
        long long time=0;
        for(int i=0;i<n;i++){
            int eated_time = ceil((double)piles[i] / speed);
            time+=eated_time;
        }

        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        n=piles.size();
        sort(begin(piles),end(piles));

        int r=piles[n-1];
        int l=1;
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(piles,mid,h)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;
    }
};