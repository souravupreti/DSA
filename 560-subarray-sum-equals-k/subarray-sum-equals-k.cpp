class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total=0;
          unordered_map<int,int> u;
        u[0] = 1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            int a=total-k;
            int o=u[a];
            if(o){
                ans+=o;
            }
            u[total]++;
        }
        return ans;
    }
};