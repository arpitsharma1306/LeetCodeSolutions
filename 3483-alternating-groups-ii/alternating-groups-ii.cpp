class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int groups=0;
        int i=0,j=1;
        while(j<2*n && i<n){
            if(colors[j%n]!=colors[(j-1)%n]){
                j++;

                if(j-i==k){
                    groups++;
                    i++;
                }
            }else{
                i=j;
                j++;
            }
        }

        return groups;
    }
};