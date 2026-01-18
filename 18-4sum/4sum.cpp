class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int start = j + 1;
                int last = n - 1;

                while (start < last) {
                    long long total =
                        1LL * nums[i] + nums[j] + nums[start] + nums[last];

                    if (total == target) {
                        ans.push_back(
                            {nums[i], nums[j], nums[start], nums[last]}
                        );

                        start++;
                        last--;

                        while (start < last && nums[start] == nums[start - 1])
                            start++;
                        while (start < last && nums[last] == nums[last + 1])
                            last--;
                    }
                    else if (total > target) {
                        last--;
                    }
                    else {
                        start++;
                    }
                }
            }
        }
        return ans;
    }
};
