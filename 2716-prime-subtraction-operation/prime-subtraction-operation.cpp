class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        int max_val = *std::max_element(nums.begin(), nums.end());
    
        vector<bool> isPrime(max_val+1, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
        for (int i = 2; i < max_val; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < max_val; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])continue;
            
                for(int j=2;j<nums[i];j++){
                    if(isPrime[j] && nums[i]-j<nums[i+1]){
                        nums[i]=nums[i]-j;
                        break;
                    }
                }
            

            if(nums[i]>=nums[i+1]) return false;
        }
        
        return true;

    }
};