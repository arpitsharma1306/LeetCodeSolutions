class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            string num=to_string(i);
            int sz=num.length();
            if(sz%2==1) continue;
            int sum1 = 0, sum2 = 0;
            for(int j=0;j<sz/2;j++){
                int digit = num[j]-'0';
                sum1+=digit;
            }
            for(int j=sz/2;j<sz;j++){
                int digit = num[j]-'0';
                sum2+=digit;
            }
            if(sum1==sum2) count++;
        }

        return count;
    }
};