class Solution {
public:
    bool isPossible(int amount,int n,vector<int>&quantities){
        int stores=0;
        for(int i=0;i<quantities.size();i++){
            stores+=static_cast<int>(std::ceil(static_cast<double>(quantities[i]) / amount));
        }
        if(stores<=n) return true;

        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int l=1;
        int r=*max_element(begin(quantities),end(quantities));
        int result=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(mid,n,quantities)){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return result;
    }
};