class Solution {
public:
    int numberOfArrays(vector<int>& differences, long long lower, long long upper) {
        int n=differences.size();
        long long lowest=lower;
        long long highest=lower;
        long long num=lower;
        for(int i=0;i<n;i++){
            num+=differences[i];
            lowest=(lowest>num)?num:lowest;
            highest=(highest<num)?num:highest;
        }

        if(highest>upper) return 0;

        long long start = lower-lowest;
        if(highest+start>upper) return 0;
        highest+=start;

        return upper-highest+1;
    }
};