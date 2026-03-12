class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> v;

        for(int i = 0; i < asteroids.size(); i++) {

            if(asteroids[i] > 0) {
                s.push(i);
            }
            else {

                while(!s.empty() && asteroids[s.top()] > 0 && 
                      asteroids[s.top()] < abs(asteroids[i])) {
                    s.pop();
                }

                if(!s.empty() && asteroids[s.top()] == abs(asteroids[i])) {
                    s.pop();
                    continue;
                }

                if(s.empty() || asteroids[s.top()] < 0) {
                    s.push(i);
                }
            }
        }

        while(!s.empty()) {
            v.push_back(asteroids[s.top()]);
            s.pop();
        }

        reverse(v.begin(), v.end());

        return v;
    }
};