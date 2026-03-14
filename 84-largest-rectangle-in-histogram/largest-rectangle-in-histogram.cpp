class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int ans = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[i] < heights[st.top()]) {

                int index = st.top();
                st.pop();

                int height = heights[index];

                if(!st.empty()) {
                    int width = i - st.top() - 1;
                    ans = max(ans, height * width);
                }
                else {
                    int width = i;
                    ans = max(ans, height * width);
                }
            }

            st.push(i);
        }

        while(!st.empty()) {

            int index = st.top();
            st.pop();

            int height = heights[index];

            if(!st.empty()) {
                int width = n - st.top() - 1;
                ans = max(ans, height * width);
            }
            else {
                int width = n;
                ans = max(ans, height * width);
            }
        }

        return ans;
    }
};