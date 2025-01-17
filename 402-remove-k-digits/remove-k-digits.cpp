class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        int i=0;
        while(k>0){
            if(i>=n && k>0){
                while(k>0){
                    st.pop();
                    k--;
                }
                break;
            }
            if(st.empty()){
                st.push(num[i]);
                i++;
                continue;
            }

            while(!st.empty() && k>0 && st.top()-'a'>num[i]-'a'){
                st.pop();
                k--;
            }
            st.push(num[i]);
            i++;
        }

        while(i<n){
            st.push(num[i]);
            i++;
        }

        if(st.empty()){
            return "0";
        }

        string result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        while(result.size() && result[result.size()-1]=='0'){
            result.pop_back();
        }

        if(result.size()==0) return "0";

        string reversed(result.rbegin(),result.rend());

        return reversed;
    }
};