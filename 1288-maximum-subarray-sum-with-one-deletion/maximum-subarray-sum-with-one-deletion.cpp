class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete=arr[0];
        int onedelete=INT_MIN;
        int ans=INT_MIN;
        for(int i=1;i<arr.size();i++){
            int prevnodelte=nodelete;
            int prevonedelete=onedelete;
            nodelete=max(nodelete+arr[i],arr[i]);
            int v2;
            if(prevonedelete==INT_MIN){
                v2=arr[i];
            }
            else{
                v2=prevonedelete+arr[i];
            }
            onedelete=max(prevnodelte,v2);
            ans=max(ans,max(nodelete,onedelete));
        }
        return ans==INT_MIN?arr[0]:ans;
        
    }
};