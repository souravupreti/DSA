class Solution {
public:
    int func(int n){
        int ans=0;
        while(n>0){
            int x=n%10;
            n=n/10;
            ans+=x*x;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;

        while(fast!=1){
            slow=func(slow);
            fast=func(fast);
            fast=func(fast);
            if(slow==fast&&fast!=1){
                return false;
            }
        }
        return true;

    }
};