class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxv=1;
        int minv=1;
        int ans=INT_MIN;
        for(int i =0;i<nums.size();i++){
            int v1=nums[i];
            int v2=maxv*nums[i];
            int v3=minv*nums[i];
            maxv=max(v1,max(v2,v3));
            minv=min(v1,min(v2,v3));
            ans=max(ans,maxv);
        }
        return ans;
    }
};