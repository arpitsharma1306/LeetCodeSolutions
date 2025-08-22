class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_prod = INT_MIN;
        for(int i=0;i<n;i++){
            int prod = nums[i];
            max_prod = max(max_prod,prod);
            for(int j=i+1;j<n;j++){
                prod *= nums[j];
                max_prod = max(max_prod,prod);
            }
        }

        return max_prod;
    }
};