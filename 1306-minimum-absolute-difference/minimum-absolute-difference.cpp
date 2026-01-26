class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int low=0;
        int high=2-1;
        int ans=INT_MAX;
        vector<vector<int>>v;
        while(high<arr.size()){
            int diff=arr[high]-arr[low];
            if(diff<ans){
                ans=diff;
                v.clear();
                v.push_back({arr[low],arr[high]});
            }
            else if(diff==ans){
                v.push_back({arr[low],arr[high]});
            }
            low++;
            high++;
        }
        return v;
    }
};