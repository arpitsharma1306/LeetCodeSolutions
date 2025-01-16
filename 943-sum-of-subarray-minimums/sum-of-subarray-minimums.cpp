class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            int count_left=0;
            int count_right=0;
            int left_i=i-1;
            int right_i=i+1;
            while(left_i>=0 && arr[i]<=arr[left_i]){
                count_left++;
                left_i--;
            }
            while(right_i<n && arr[i]<arr[right_i]){
                right_i++;
                count_right++;
            }

            long long val=(count_left+1)*(count_right+1);
            sum+=val*arr[i];
        }
        const int MOD = 1000000007;
        return sum%MOD;
    }
};