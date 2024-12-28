class Solution {
public:
    int t[20001][4];
    int helper(vector<int>&subarray,int count,int i,int k){
        if(count==0) return 0;
        if(i>=subarray.size()) return INT_MIN;

        if(t[i][count]!=-1) return t[i][count];

        int taken = subarray[i] + helper(subarray,count-1,i+k,k);
        int skip  = helper(subarray,count,i+1,k);

        return t[i][count] = max(taken,skip);
    }
    void solve(vector<int>&subarray,int count,int i,int k,vector<int>&result){
        if(count==0) return;
        if(i>subarray.size()) return;

        int taken = subarray[i] + helper(subarray,count-1,i+k,k);
        int skip  = helper(subarray,count,i+1,k);

        if(taken>=skip){
            result.push_back(i);
            solve(subarray,count-1,i+k,k,result);
        }else{
            solve(subarray,count,i+1,k,result);
        }
        return;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(t,-1,sizeof(t));
        int n=nums.size();
        vector<int>subarray;
        int windowSum=0;
        int j=0;
        int i=0;
        while(j<n){
            windowSum+=nums[j];
            if(j-i+1==k){
                subarray.push_back(windowSum);
                windowSum-=nums[i];
                i++;
            }
            j++;
        }

        vector<int>result;
        solve(subarray,3,0,k,result);
        return result;
    }
};