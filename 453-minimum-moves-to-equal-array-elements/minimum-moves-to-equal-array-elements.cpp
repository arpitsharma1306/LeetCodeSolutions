class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        int moves = 0;
        for(int& num:nums){
            moves += (num-mini);
        }

        return moves;
        
    }
};