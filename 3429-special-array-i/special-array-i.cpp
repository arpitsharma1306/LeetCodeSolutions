class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int isOdd=(nums[0]%2);
        for(int i=1;i<n;i++){
            cout<<isOdd<<" ";
            if(isOdd==(nums[i]%2)) return false;
            isOdd=1-isOdd;
        }

        return true;
    }
};