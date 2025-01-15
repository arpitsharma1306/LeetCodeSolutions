class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>cumSum(n);
        cumSum[0]=0;
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                cumSum[i]=cumSum[i-1]+1;
            }else{
                cumSum[i]=cumSum[i-1];
            }
        }

        vector<bool>result(queries.size());
        int i=0;
        for(auto& query:queries){
            int start=query[0];
            int end=query[1];
            if(cumSum[end]-cumSum[start]==0){
                result[i]=true;
            }else{
                result[i]=false;
            }
            i++;
        }

        return result;
    }
};