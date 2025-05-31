class Solution {
public:
    int binarySearch(vector<int>& nums, int maxDiff,int i){
        int start=i;
        int end=nums.size()-1;
        int ans=i;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]-nums[i]<=maxDiff){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>index(n);
        for(int i=0;i<n;i++){
            index[i]=binarySearch(nums,maxDiff,i);
        }
        vector<int>group(n);
        int groupnum=1;
        group[0]=1;
        for(int i=1;i<n;i++){
            if(index[i-1]<i) group[i]=++groupnum;
            else group[i]=groupnum;
        }

        int m=queries.size();
        vector<bool>ans(m);
        for(int i=0;i<m;i++){
            int u=queries[i][0], v=queries[i][1];
            if(group[u]==group[v]) ans[i]=true;
            else ans[i]=false;
        }

        return ans;
    }
};