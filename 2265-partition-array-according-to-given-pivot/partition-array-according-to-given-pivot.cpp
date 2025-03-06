class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>res(n);
        int pivot_cnt=0;
        int j=0;

        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                res[j]=nums[i];
                j++;
            }
            if(nums[i]==pivot){
                pivot_cnt++;
            }
        }

        while(pivot_cnt>0){
            res[j]=pivot;
            j++;
            pivot_cnt--;
        }

        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                res[j]=nums[i];
                j++;
            }
        }

        return res;
    }
};