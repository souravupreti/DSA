class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>p;
        for(int i=0;i<nums.size();i++){
            p.push(nums[i]);
        }
        k=k-1;
        while(k&&(!p.empty())){
            p.pop();
            k--;
        }
        return p.top();
    }
};