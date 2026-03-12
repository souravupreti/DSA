class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;

        for(int i = 0; i < asteroids.size(); i++) {

            if(asteroids[i] > 0) {
                s.push_back(i);
            }
            else {

                while(!s.empty() && asteroids[s.back()] > 0 &&
                      asteroids[s.back()] < abs(asteroids[i])) {
                    s.pop_back();
                }

                if(!s.empty() && asteroids[s.back()] == abs(asteroids[i])) {
                    s.pop_back();
                    continue;
                }

                if(s.empty() || asteroids[s.back()] < 0) {
                    s.push_back(i);
                }
            }
        }

        vector<int> ans;
        for(int idx : s) ans.push_back(asteroids[idx]);

        return ans;
    }
};