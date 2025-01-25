class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>vec; 
        for(int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }
        sort(begin(vec),end(vec));

        int l=0;
        while(l<n){
            int r=l+1;
            while(r<n && abs(vec[r].first-vec[r-1].first)<=limit){
                r++;
            }
            vector<int>idxs;
            for(int i=l;i<r;i++){
                idxs.push_back(vec[i].second);
            }
            sort(begin(idxs),end(idxs));

            for(int idx:idxs){
                nums[idx] = vec[l].first;
                l++;
            }
        }

        return nums;
    }
};