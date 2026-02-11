class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int one = 0;
        int ans = 0;

        unordered_map<int,int> u;

        u[0] = -1;   // Important base case

        for(int i = 0; i < n; i++) {

            if(nums[i] == 0)
                zero++;
            else
                one++;

            int diff = zero - one;

            if(u.find(diff) != u.end()) {
                int index = u[diff];
                int length = i - index;
                ans = max(ans, length);
            }
            else {
                u[diff] = i;
            }
        }

        return ans;
    }
};
