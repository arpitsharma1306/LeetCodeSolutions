class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string fraction;
        if((numerator<0) ^ (denominator<0)) fraction+="-";

        long long dividend = llabs((long long) numerator);
        long long divisor = llabs((long long) denominator);

        fraction += to_string(dividend/divisor);
        long long rem = dividend%divisor;
        if(rem==0) return fraction;
        fraction+=".";
        unordered_map<long long,int>mp;
        while(rem){
            if(mp.count(rem)){
                fraction.insert(mp[rem],"(");
                fraction+=")";
                return fraction;
            }
            mp[rem] = fraction.size();
            rem *= 10;
            fraction += to_string(rem/divisor);
            rem %= divisor;
        }

        return fraction;
    }
};