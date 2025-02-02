class Solution {
public:

    int maxDistance(string s, int k) {
        int n=s.size();
        int north=0,south=0,east=0,west=0;
        int maxD=0;
        for(int i=0;i<n;i++){
            if(s[i]=='N') north++;
            else if(s[i]=='S') south++;
            else if(s[i]=='W') west++;
            else if(s[i]=='E') east++;

            int moves=k, dist=0;

            if(north>=south){
                if(k>south){
                    dist+=(north+south);
                    moves-=south;
                }else{
                    dist+=(north+k+k-south);
                    moves=0;
                }
            }else{
                if(k>north){
                    dist+=(north+south);
                    moves-=north;
                }else{
                    dist+=(south+k+k-north);
                    moves=0;
                }
            }

            if(east>=west){
                if(moves>west){
                    dist+=(east+west);
                    moves-=west;
                }else{
                    dist+=(east+moves+moves-west);
                    moves=0;
                }
            }else{
                if(moves>east){
                    dist+=(east+west);
                }else{
                    dist+=(west+moves+moves-east);
                }
            }

            maxD=max(maxD,dist);
        }

        return maxD;
    }
};