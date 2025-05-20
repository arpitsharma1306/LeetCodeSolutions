class Solution {
public:
    int minOperations(vector<int>& nums) {
        int oper = 0;
        stack<int> st;

        for (int num : nums) {
            if (num == 0) {
                oper += st.size();
                while (!st.empty()) {
                    st.pop();
                }
            } else {
                if (st.empty() || st.top() < num) {
                    st.push(num);
                } else {
                    while (!st.empty() && st.top() > num) {
                        st.pop();
                        oper++;
                    }
                    if (st.empty() || st.top() != num) {
                        st.push(num);
                    }
                }
            }
        }
        oper += st.size();
        return oper;
    }
};