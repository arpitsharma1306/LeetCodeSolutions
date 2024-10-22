class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();

        if(n==1) return 1;

        vector<int>left(n,1);
        vector<int>right(n,1);
        int count=0;

        if(ratings[0]>ratings[1]) left[0]++;
        for(int i=1;i<n-1;i++){
            if(ratings[i]>ratings[i-1] || ratings[i]>ratings[i+1]){
                if(ratings[i]>ratings[i-1] && ratings[i]<=ratings[i+1]){
                    left[i]+=left[i-1];
                }else if(ratings[i]>ratings[i+1] && ratings[i]<=ratings[i-1]){
                    left[i]+=left[i+1];
                }else{
                    int num=max(left[i-1],left[i+1]);
                    left[i]+=num;
                }
            }
        }
        if(ratings[n-1]>ratings[n-2]) left[n-1]+=left[n-2];

        if(ratings[n-1]>ratings[n-2]) right[n-1]++;
        for(int i=n-2;i>0;i--){
            if(ratings[i]>ratings[i-1] || ratings[i]>ratings[i+1]){
                if(ratings[i]>ratings[i-1] && ratings[i]<=ratings[i+1]){
                    right[i]+=right[i-1];
                }else if(ratings[i]>ratings[i+1] && ratings[i]<=ratings[i-1]){
                    right[i]+=right[i+1];
                }else{
                    int num=max(right[i-1],right[i+1]);
                    right[i]+=num;
                }
            }
        }
        if(ratings[0]>ratings[1]) right[0]+=right[1];

        for(int i=0;i<n;i++){
            int num=max(left[i],right[i]);
            cout<<left[i]<<" ";
            count+=num;
        }

        return count;

    }
};