class Solution {
public:
    vector<int> getNSL(vector<int>&height){
        int n=height.size();
        stack<int>st;
        vector<int>result(n,-1);

        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(!st.empty()) result[i]=st.top();
            st.push(i);
        }

        return result;
    }
    vector<int> getNSR(vector<int>&height){
        int n=height.size();
        stack<int>st;
        vector<int>result(n,n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(!st.empty()) result[i]=st.top();
            st.push(i);
        }

        return result;
    }
    int findMaxArea(vector<int>&height){
        vector<int> NSL = getNSL(height);
        vector<int> NSR = getNSR(height);
        int maxi=0;

        for(int i=0;i<height.size();i++){
            int width = NSR[i]-NSL[i]-1;
            int area=width*height[i];
            maxi=max(maxi,area);
        }

        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> height(n);

        for(int i=0;i<n;i++){
            if(matrix[0][i]=='1'){
                height[i]=1;
            }else{
                height[i]=0;
            }
        }

        int maxArea=findMaxArea(height);
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0'){
                    height[j]=0;
                }else{
                    height[j]+=1;
                }
            }
            maxArea=max(maxArea,findMaxArea(height));
        }

        return maxArea;
    }
};