class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        unordered_set<int>st;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && i!=k && j!=k){
                        if(digits[i]!=0){
                            if(digits[k]%2==0){
                                int num=digits[i]*100+digits[j]*10+digits[k];
                                st.insert(num);
                            }
                        }
                    }
                }
            }
        }

        return st.size();
    }
};