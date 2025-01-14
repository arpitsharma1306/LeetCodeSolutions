class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum=0;
        int count=0;
        unordered_set<int>st;
        for(int i=0;i<banned.size();i++){
            st.insert(banned[i]);
        }
        int num=1;

        while(num<=n){
            if(st.find(num)==st.end()){
                sum+=num;
                if(sum<=maxSum) count++;
                else break;
            }
            num++;
        }

        return count;
    }
};