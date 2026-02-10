class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int ans=0;
        unordered_map<int,int> u; 
        u[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int n=sum%k;
            if(n<0){
                n=n+k;
            }
            ans+=u[n];
            u[n]++;
        }
        return ans;

    }
};