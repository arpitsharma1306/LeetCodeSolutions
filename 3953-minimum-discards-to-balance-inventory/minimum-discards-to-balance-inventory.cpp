class Solution {
public:
    int minArrivalsToDiscard(vector<int>& nums, int w, int m) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        int i = 0;
        vector<int>idx;
        for (; i < w; i++) {
            mp[nums[i]]++;
            idx.push_back(i);
            if (mp[nums[i]] > m) {
                idx.pop_back();
                mp[nums[i]]--;
                cnt++;
            }
        }
        int k=0;

        for (; i < n;i++ ) {
            if(i-w==idx[k]){
                mp[nums[idx[k]]]--;
                k++;
            }
            mp[nums[i]]++;
            idx.push_back(i);
            if (mp[nums[i]] > m) {
                mp[nums[i]]--;
                idx.pop_back(); 
                cnt++;
            }
        }

        return cnt;
    }
};