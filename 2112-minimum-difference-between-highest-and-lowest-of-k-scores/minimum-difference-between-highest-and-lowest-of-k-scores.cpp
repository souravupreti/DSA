class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
          if (k == 1) return 0; 
        sort(nums.begin(),nums.end());

        int low=0;
        int high=k-1;
        int ans=INT_MAX;
        while(high<nums.size()){
            ans=min(ans,nums[high]-nums[low]);
            low++;
            high++;
        }
        return ans;
    }
};