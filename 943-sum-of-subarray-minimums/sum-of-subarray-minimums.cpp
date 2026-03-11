class Solution {
public:

    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse(arr.size(),arr.size());
        vector<int>pse(arr.size(),-1);
        stack<int>s;
        int mod=(int)1e9+7;
        for(int i=0;i<arr.size();i++){
            while(!s.empty()&&arr[s.top()]>arr[i]){
                nse[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=arr.size()-1;i>=0;i--){
            while(!s.empty()&&arr[s.top()]>=arr[i]){
                pse[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            int right=nse[i]-i;
            int left=i-pse[i];
            ans=(ans+(((long long)right*left%mod)*arr[i])%mod)%mod;
        }
        return (int)ans;

    }
};