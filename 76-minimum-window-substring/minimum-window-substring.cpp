class Solution {
public:
    bool check(vector<int>& need, vector<int>& have) {
        for (int i = 0; i < 256; i++) {
            if (need[i] > have[i]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int low = 0, high = 0;
        vector<int> have(256, 0);
        vector<int> need(256, 0);

        // CHANGE 1: correct indexing
        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
        }

        int diff = INT_MAX;   // CHANGE 2: initialize properly
        int start = 0;        // CHANGE 3: initialize

        for (; high < s.size(); high++) {

            // CHANGE 4: correct indexing
            have[s[high]]++;

            while (check(need, have)) {
                int length = high - low + 1;

                if (length < diff) {
                    diff = length;
                    start = low;
                }

                // CHANGE 5: decrease HAVE, not NEED
                have[s[low]]--;
                low++;
            }
        }

        // CHANGE 6: handle no valid window
        if (diff == INT_MAX) return "";

        return s.substr(start, diff);
    }
};
