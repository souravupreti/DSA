class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>high(nums2.size(),-1);
        stack<int>s1;
        unordered_map<int,int>m;
       for(int i=0;i<nums2.size();i++){
        while(!s1.empty()&& nums2[s1.top()]<nums2[i]){
            high[s1.top()]=nums2[i];
            s1.pop();
        }
        s1.push(i);
       }
       for(int i=0;i<nums2.size();i++){
        m.insert({nums2[i],high[i]});
       }
       vector<int>result;
       for(int i=0;i<nums1.size();i++){
        result.push_back(m[nums1[i]]);
       }
        return result;

        
    }
};