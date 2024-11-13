#define ll long long
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
         sort(nums.begin(),nums.end());
       
         ll ans = 0;         
         ll n = size(nums);
         for(ll i = 0;i<n;i++){

             ll currentNumber = nums[i];
             ll leftRange = lower-nums[i];
             ll rightRange = upper-nums[i];
             
             int smallest = lower_bound(nums.begin()+i+1,nums.end(),leftRange)-nums.begin();
             int largest = upper_bound(nums.begin()+i+1,nums.end(),rightRange)-nums.begin();
              
ans += largest-smallest;
         }
         return ans;
    }
};