class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;

        while(true){
            slow=nums[slow];
            fast=nums[fast];
            fast=nums[fast];
            if(slow==fast){
                slow=0;
                while(slow!=fast){
                    fast=nums[fast];
                    slow=nums[slow];
                }
                return slow;
            }
        }
        return -1;
    }
};