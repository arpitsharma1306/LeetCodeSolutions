class Solution {
public:
    int MOD = 1e9+7;
    int mem[1002][1024];
    int count_ways(int &m,int &n,int r,int c,int curr_state,int prev_state){
        if(c==n) return 1;
        if(r==m) return count_ways(m,n,0,c+1,0,curr_state);

        if(r==0 and mem[c][prev_state]!=-1) return mem[c][prev_state];

        int no_of_ways=0;

        int upper_color = (r>0)?(curr_state & 3):0;
        int left_color = (prev_state>>((m-r-1)*2)) & 3;
        for(int color=1;color<=3;color++){
            if(upper_color!=color && left_color!=color){
                no_of_ways= (no_of_ways+count_ways(m,n,r+1,c,(curr_state<<2)+color,prev_state))%MOD;
            }
        }
        if(r==0) mem[c][prev_state] = no_of_ways;
        return no_of_ways;
    }
    int colorTheGrid(int m, int n) {
        memset(mem,-1,sizeof(mem));

        return count_ways(m,n,0,0,0,0);
    }
};