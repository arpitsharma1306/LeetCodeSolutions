class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        long long sum=0;
        long long maxi=INT_MIN;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                sum+=1;
            }else{
                sum-=1;
            }

            if(sum>maxi){
                maxi=sum;
                idx=i;
            }
        }

        if(maxi<=0) return 0;

        return idx+1;
        
    }
};