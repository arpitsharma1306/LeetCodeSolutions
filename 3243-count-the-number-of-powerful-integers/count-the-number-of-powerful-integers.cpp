class Solution {
public:
    long long solve(string str,int limit,string suffix){
        if(str.length() < suffix.length()){
            return 0;
        }

        long long count = 0;
        string trailString = str.substr(str.length()-suffix.length());
        int remainL = str.length()-suffix.length();

        for(int i=0;i<remainL;i++){
            int digit = str[i]-'0';
            if(digit<=limit){
                count+=digit*pow(limit+1,remainL-i-1);
            }else{
                count+=pow(limit+1,remainL-i);
                return count;
            }
        }

        if(trailString >= suffix){
            count+=1;
        }

        return count;
    }
    long long numberOfPowerfulInt(long long _start, long long _finish, int limit, string s) {
        string start = to_string(_start-1);
        string finish = to_string(_finish);

        return solve(finish,limit,s) - solve(start,limit,s);
    }
};