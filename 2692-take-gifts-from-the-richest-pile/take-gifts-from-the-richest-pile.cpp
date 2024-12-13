class Solution {
public:
    int findMax(vector<int>& gifts,int &idx){
        int maxi=0;
        for(int i=0;i<gifts.size();i++){
            if(gifts[i]>maxi){
                idx=i;
                maxi=gifts[i];
            }
        }

        return maxi;
    }
    long long pickGifts(vector<int>& gifts, int k) {
        
        for(int i=0;i<k;i++){
            int idx=-1;
            int maxi=findMax(gifts,idx);
            int num=sqrt(maxi);
            gifts[idx]=num;
        }

        long long cnt=0;

        for(int &val:gifts){
            cnt+=val;
        }

        return cnt;
    }
};