class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        vector<int>primes(1001,0);
        primes[2]=1;
        for(int i=3;i<1002;i++){
            int flag=true;
            for(int j=2;j<i;j++){
                if(i%j==0){
                    flag=false;
                    break;
                }
            }
            if(flag) primes[i]=1;
        }
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])continue;
            
                for(int j=2;j<nums[i];j++){
                    if(primes[j] && nums[i]-j<nums[i+1]){
                        nums[i]=nums[i]-j;
                        break;
                    }
                }
            

            if(nums[i]>=nums[i+1]) return false;
        }
        
        return true;

    }
};