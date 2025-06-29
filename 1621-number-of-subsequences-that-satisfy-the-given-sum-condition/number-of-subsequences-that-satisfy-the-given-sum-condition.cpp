class Solution {
public:
    const int MOD = 1e9+7;

    long long power(long long base, int exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    long long solve(vector<int>& nums,int i, int target){
        int low = i;
        int high = nums.size()-1;
        int ans = low;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[i]+nums[mid]<=target){
                low = mid+1;
                ans = mid;
            }else{
                high = mid-1;
            }
        }
        if(ans==i) return (nums[ans]+nums[ans]<=target)?1:0;

        long long combination = power(2,ans-i)%MOD;

        return combination;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long cnt = 0;
        for(int i=0;i<n;i++){
            cnt = (cnt + solve(nums,i,target))%MOD;
        }

        return cnt;
    }
};