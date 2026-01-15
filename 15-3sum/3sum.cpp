class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=nums.size()-1;
            int target=-1*nums[i];
            while(left<right){
                if(nums[left]+nums[right]==target){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<nums.size() &&nums[left]==nums[left-1]){
                        left++;
                    }
                    while(right>=0&&nums[right]==nums[right+1]){
                        right--;
                    }
                }
                else if(nums[left]+nums[right]>target){
                    right--;
                }
                else{
                    left++;
            }
            
        }
       
    }
     return ans;
    }
};