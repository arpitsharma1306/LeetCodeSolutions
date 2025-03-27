class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(nums);
        sort(begin(temp),end(temp));
        int i=n-1, j=0, k=i/2+1;
        while(i>=0){
            if(i%2==1){
                nums[i]=temp[k];
                k++;
            }else{
                nums[i]=temp[j];
                j++;
            }
            i--;
        }
    }
};