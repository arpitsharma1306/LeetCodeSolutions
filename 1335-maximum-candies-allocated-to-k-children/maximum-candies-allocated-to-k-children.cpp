class Solution {
public:
    bool isPossible(vector<int>& candies, long long k,int each_get){
        int n=candies.size();
        n--;
        while(k>0 && n>=0){
            int childs = candies[n]/each_get;
            if(childs==0) break;
            k-=childs;
            n--;
            if(k<=0) return true;
        }

        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        sort(candies.begin(),candies.end());
        int low=1, high=candies[n-1];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(candies,k,mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return ans;
    }
};