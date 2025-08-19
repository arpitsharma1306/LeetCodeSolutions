class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n), right(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(s.empty()) left[i]=0;
            else left[i] = s.top()+1;

            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }

            if(s.empty()) right[i] = n-1;
            else right[i] = s.top()-1;

            s.push(i);
        }

        int maxA = 0;
        for(int i=0;i<n;i++){
            maxA = max(maxA,(right[i]-left[i]+1)*heights[i]);
        }

        return maxA;
    }
};