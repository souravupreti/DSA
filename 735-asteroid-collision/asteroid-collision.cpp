class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {

        stack<int> st;
        
        for (int asteroid : arr) {
            bool destroyed = false;
            
            // collision happens only if top > 0 and asteroid < 0
            while (!st.empty() && st.top() > 0 && asteroid < 0) {
                if (st.top() < abs(asteroid)) {
                    st.pop(); // top asteroid destroyed
                    continue;
                } else if (st.top() == abs(asteroid)) {
                    st.pop(); // both destroyed
                }
                destroyed = true; // current asteroid destroyed
                break;
            }
            
            if (!destroyed) {
                st.push(asteroid);
            }
        }
        
        // convert stack to vector
        vector<int> v(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            v[i] = st.top();
            st.pop();
        }
        return v;
         }
};