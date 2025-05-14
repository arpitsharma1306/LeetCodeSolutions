class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int>st;
        int n=digits.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int num1=digits[i]*100+digits[j]*10+digits[k];
                    int num2=digits[j]*100+digits[i]*10+digits[k];
                    int num3=digits[k]*100+digits[i]*10+digits[j];
                    int num4=digits[i]*100+digits[k]*10+digits[j];
                    int num5=digits[k]*100+digits[j]*10+digits[i];
                    int num6=digits[j]*100+digits[k]*10+digits[i];

                    if(num1>=100 && num1%2==0 && st.find(num1)==st.end()){
                        st.insert(num1);
                        ans.push_back(num1);
                    }
                    if(num2>=100 && num2%2==0 && st.find(num2)==st.end()){
                        st.insert(num2);
                        ans.push_back(num2);
                    }
                    if(num3>=100 && num3%2==0 && st.find(num3)==st.end()){
                        st.insert(num3);
                        ans.push_back(num3);
                    }
                    if(num4>=100 && num4%2==0 && st.find(num4)==st.end()){
                        st.insert(num4);
                        ans.push_back(num4);
                    }
                    if(num5>=100 && num5%2==0 && st.find(num5)==st.end()){
                        st.insert(num5);
                        ans.push_back(num5);
                    }
                    if(num6>=100 && num6%2==0 && st.find(num6)==st.end()){
                        st.insert(num6);
                        ans.push_back(num6);
                    }
                }
            }
        }

        sort(begin(ans),end(ans));

        return ans;
    }
};