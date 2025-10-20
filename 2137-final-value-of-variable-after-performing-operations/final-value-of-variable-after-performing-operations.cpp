class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(auto &str:operations){
            if(str=="++X" || str=="X++") res++;
            else res--;
        }

        return res;
    }
};