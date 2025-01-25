class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>vec = nums;
        sort(vec.begin(),vec.end());

        int groupNum=0;
        unordered_map<int,int>numToGroup;
        unordered_map<int,list<int>>groupList;

        numToGroup[vec[0]] = groupNum;
        groupList[groupNum].push_back(vec[0]);

        for(int i=1;i<n;i++){
            if(abs(vec[i]-vec[i-1])>limit) groupNum++;

            numToGroup[vec[i]] = groupNum;
            groupList[groupNum].push_back(vec[i]);
        }

        vector<int>result(n);

        for(int i=0;i<n;i++){
            int num = nums[i];
            int group = numToGroup[num];
            result[i] = *groupList[group].begin();
            groupList[group].pop_front();
        }

        return result;
    }
};