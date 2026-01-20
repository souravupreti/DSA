class Solution {
public:
    int findMax(vector<int> &c) {          // char → int
        int maxElement = INT_MIN;
        for (int i = 0; i < c.size(); i++) {
            maxElement = max(maxElement, c[i]);
        }
        return maxElement;
    }

    int characterReplacement(string s, int k) {
        vector<int> c(26, 0);              // char → int
        int ans = 0;                       // INT_MIN → 0
        int low = 0;                       // added
        int high = 0;                      // added

        for (high = 0; high < s.size(); high++) {
            c[s[high] - 'A']++;            // fixed index

            int length = high - low + 1;
            int maxElement = findMax(c);
            int diff = length - maxElement; // removed +1

            while (diff > k) {
                c[s[low] - 'A']--;          // fixed index
                low++;

                length = high - low + 1;
                maxElement = findMax(c);
                diff = length - maxElement;
            }

            if (diff <= k) {
                length = high - low + 1;
                ans = max(ans, length);     // removed redeclaration
            }
        }
        return ans;
    }
};
