class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>posi = nums;
        int positive = 0;
        int negative = 0;
        for(int i=0;i<n-1;i++){
            if(posi[i]==-1){
                positive++;
                if(posi[i+1]==1){
                    posi[i+1]=-1;
                }else{
                    posi[i+1]=1;
                }
            }
            if(positive>k) break;
        }

        if(posi[n-1]!=-1 && positive<=k){
            return true;
        }

        for(int i=0;i<n-1;i++){
            if(nums[i]==1){
                negative++;
                if(nums[i+1]==1){
                    nums[i+1]=-1;
                }else{
                    nums[i+1]=1;
                }
            }
            if(negative>k) break;
        }

        if(nums[n-1]!=1 && negative<=k){
            return true;
        }


        return false;
    }
};