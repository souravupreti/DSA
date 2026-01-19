class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0;
        int high=0;
        int ans=INT_MAX;
        int sum=0;
        while(high<nums.size()){
            sum+=nums[high];
            while(sum>=target){
                ans=min(ans,high-low+1);
                sum=sum-nums[low];
                low++;
            }
            high++;
        }
        return ans==INT_MAX?0:ans;


    }
};