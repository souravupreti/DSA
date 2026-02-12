class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n =arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
          int start=arr[0][0];
            int end=arr[0][1];
        for(int i=1;i<n;i++){
            int start2=arr[i][0];
            int end2=arr[i][1];
            if(end>=start2){
                start=start;
                end=max(end,end2);
                continue;
            }
            ans.push_back({start,end});
            start=start2;
            end=end2;
        }
        ans.push_back({start,end});

return ans;
        
    }
};