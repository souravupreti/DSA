class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>p;
        for(int i=0;i<stones.size();i++){
            p.push(stones[i]);
        }
        while(p.size()>1){
            int a=p.top();
            p.pop();
            int b=a-p.top();
            p.pop();
            p.push(b);
        }
        return p.top();
    }
};