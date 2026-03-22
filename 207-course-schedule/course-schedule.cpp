class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            ans.push_back(a);
            for(auto it:adj[a]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans.size() == V; // FIXED
    }
};