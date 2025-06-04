class Solution {
public:
    int minimumOperations(string num) {
        int n=num.size();
        if(n==1 && num[0]!='0') return 1;
        bool zero = false, five = false;
        reverse(num.begin(),num.end());
        int i=0;
        for(;i<n;i++){
            if(num[i]=='0'){
                if(zero==true) break;
                else zero = true;
            }
            if(num[i]=='7' && five==true) break;
            if(num[i]=='2' && five==true) break;
            if(num[i]=='5'){
                if(zero==true) break;
                else five=true;
            }
        }

        if(i==n && !zero) return n;

        return i-1;
    }
};