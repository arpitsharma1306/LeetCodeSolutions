class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> freq; 
        int maxFreq = 0, maxElement = nums[0];

        for (int num : nums) {
            freq[num]++;
            if (freq[num] > maxFreq) {
                maxFreq = freq[num];
                maxElement = num;
            }
        }
        freq.clear(); 
        double maxiFreq=0;
        vector<double>left(n), right(n);
        for(int i=0;i<n;i++){
            if(nums[i]==maxElement) maxiFreq++;
            left[i]=(double)(maxiFreq/(double)(i+1));
        }
        maxiFreq=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==maxElement) maxiFreq++;
            right[i]=(double)(maxiFreq/(double)(n-i));
        }

        for(int i=0;i<n-1;i++){
            if(left[i]>0.5 && right[i+1]>0.5){
                return i;
            }
        }

        return -1;
    }
};