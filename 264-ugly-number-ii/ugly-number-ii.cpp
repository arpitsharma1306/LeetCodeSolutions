class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n+1,0);
        arr[1]=1;
        //i2 i3 i5 are pointers pointing at index of arr.
        int i2=1;
        int i3=1;
        int i5=1;

        for(int i=2;i<=n;i++){
            int i2th = arr[i2]*2;
            int i3th = arr[i3]*3;
            int i5th = arr[i5]*5;

            int minUgly = min({i2th,i3th,i5th});
            arr[i] = minUgly;

            if(minUgly == i2th) i2++;
            if(minUgly == i3th) i3++;
            if(minUgly == i5th) i5++;
        }

        return arr[n];
    }
};