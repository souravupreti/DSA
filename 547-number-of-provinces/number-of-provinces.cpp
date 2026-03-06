class Solution {
public:
void dfs(vector<vector<int>> adj,vector<int>&v,int src){
    v[src]=1;
    for(auto it:adj[src]){
        if(!v[it]) 
        {
            dfs(adj,v,it);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>v(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!v[i]){
                count++;
                dfs(adj,v,i);
            }
        }
        return  count;
    }
};