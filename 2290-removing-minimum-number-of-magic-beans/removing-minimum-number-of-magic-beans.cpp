class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        if(n==1) return 0;
        sort(begin(beans),end(beans));
        long long remove=0;
        for(int i=1;i<n;i++){
            remove+=(long long)(beans[i]-beans[0]);
        }

        long long min_remove=remove;

        for(int i=0;i<n-1;i++){
            int delete_bean=beans[i];
            remove+=delete_bean;
            long long gap=beans[i+1]-beans[i];
            long long diff=(long long)((n-i-1)*gap);
            remove-=diff;
            min_remove=min(min_remove,remove);
        }

        return min_remove;
    }
};