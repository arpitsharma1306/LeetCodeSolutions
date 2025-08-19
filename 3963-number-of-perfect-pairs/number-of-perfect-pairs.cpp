class Solution {
public:
    bool check(vector<int>& nums,int end,int start){
        int a = nums[start], b = nums[end];

        return ((min(abs(a - b), a + b) <= min(a, b)) && (max(abs(a - b), a + b) >= max(a,b)));
    }
    long long perfectPairs(vector<int>& nums) {
        int n=nums.size();
        for(int &num:nums) num = abs(num);
        sort(nums.begin(),nums.end());
        long long cnt = 0;
        for(int i=0;i<n;i++){
            int low = i+1;
            int high = n-1;
            int ans = -1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(check(nums,mid,i)){
                    ans = mid;
                    low=mid+1;
                }else{
                    high = mid-1;
                }
            }

            if(ans!=-1) cnt+=(ans-i);
        }

        return cnt;
    }
};