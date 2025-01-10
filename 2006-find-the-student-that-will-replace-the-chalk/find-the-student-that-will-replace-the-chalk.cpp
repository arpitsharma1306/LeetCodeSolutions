class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        int i=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=chalk[i];
        }
        k=k%sum;
        while(k>0){
            k-=chalk[i];
            if(k<0){
                return i;
            }
            i++;
            i=i%n;
        }
        return i;
    }
};