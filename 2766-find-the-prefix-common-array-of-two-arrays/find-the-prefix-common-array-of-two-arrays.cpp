class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_set<int>st1;
        unordered_set<int>st2;
        unordered_set<int>common;
        vector<int>result(n);
        int count=0;
        for(int i=0;i<n;i++){
            st1.insert(A[i]);
            st2.insert(B[i]); 
            if(st1.find(B[i])!=st1.end() && common.find(B[i])==common.end()){
                count++;
                common.insert(B[i]);
            }
            if(st2.find(A[i])!=st2.end() && common.find(A[i])==common.end()){
                count++;
                common.insert(A[i]);
            }
            result[i]=count;
        }

        return result;
    }
};