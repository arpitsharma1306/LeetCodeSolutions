class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        bool deleted = false, ones = false, zeros = false;
        int maxlen = 0, len=0;
        int i=0,j=0;
        while(j<n){
            if(nums[j]==1){
                ones = true;
                len++;
                cout<<len<<" ";
                maxlen = max(maxlen,len);
                j++;
            }
            else if(nums[j]==0 && deleted == false){
                zeros = true;
                if(len==0){
                    j++;
                    i=j;
                    continue;
                }
                deleted = true;
                j++;
                // maxlen = max(maxlen,len);
            }else{
                while(i<j && nums[i]!=0){
                    i++;
                    len--;
                    cout<<len<<" ";
                }
                i++;
                j++;
            }
        }

        if(!ones) return 0;
        if(!deleted && !zeros) return n-1;

        return maxlen;
    }
};