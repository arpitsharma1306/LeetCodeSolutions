class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        list<int>v(nums.begin(),nums.end());
        int count=0;

        while(!is_sorted(v.begin(),v.end())){
            auto it1 = v.begin();
            auto it2 = next(it1);

            auto minIt1 = it1;
            auto minIt2 = it2;
            int minSum = *it1 + *it2;
            while(it2!=v.end()){
                int sum = *it1 + *it2;
                if(sum<minSum){
                    minIt1 = it1;
                    minIt2 = it2;
                    minSum = sum;
                }
                ++it1;
                ++it2;
            }
            int sum = *minIt1 + *minIt2;
             v.erase(minIt2);
            auto insertPos = v.erase(minIt1);
            v.insert(insertPos,sum);
            count++;
        }

        return count;
    }
};