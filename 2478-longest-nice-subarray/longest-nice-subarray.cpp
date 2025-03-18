class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        long long sum=nums[0];
        long long XOR=nums[0];
        int largest=1;
        int i=0,j=1;
        while(j<n){
            sum+=nums[j];
            XOR^=nums[j];
            if(sum==XOR){
                largest=max(largest,j-i+1);
                j++;
                continue;
            }

            while(i<j && sum!=XOR){
                sum-=nums[i];
                XOR^=nums[i];
                i++;
            }
            j++;
        }

        return largest;
    }
};