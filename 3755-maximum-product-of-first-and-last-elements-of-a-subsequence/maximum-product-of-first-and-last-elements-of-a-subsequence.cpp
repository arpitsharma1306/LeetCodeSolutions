class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        vector<pair<int,int>>arr(n);
        arr[n-1].first = nums[n-1];
        arr[n-1].second = nums[n-1];

        for(int i=n-2;i>=0;i--){
            arr[i].first = max(arr[i+1].first,nums[i]);
            arr[i].second = min(arr[i+1].second,nums[i]);
        }

        long long answer = LLONG_MIN;

        for(int i=0;i<=n-m;i++){
            int a = nums[i];
            int large = arr[i+m-1].first;
            int small = arr[i+m-1].second;
            answer = max({1LL*a*large,1LL*a*small,answer});
        }

        return answer;


    }
};