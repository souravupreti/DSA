class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> u;
        int low = 0;
        int ans = 0;

        for (int high = 0; high < fruits.size(); high++) {
            u[fruits[high]]++;

            while (u.size() > 2) {
                u[fruits[low]]--;
                if (u[fruits[low]] == 0) {
                    u.erase(fruits[low]);
                }
                low++;
            }

            int length = high - low + 1;
            ans = max(ans, length);
        }
        return ans;
    }
};
