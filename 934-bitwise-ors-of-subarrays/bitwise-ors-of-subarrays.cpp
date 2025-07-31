class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>res;
        unordered_set<int>prev;

        for(int &x:arr){
            unordered_set<int>curr;
            curr.insert(x);
            for(int y:prev){
                curr.insert(x|y);
            }

            res.insert(curr.begin(),curr.end());
            prev=curr;
        }


        return res.size();
    }
};