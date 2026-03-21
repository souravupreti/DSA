class Solution {
public:
    bool dfs(int src,vector<vector<int>>& graph,vector<int>&v,int c){
        v[src]=c;
        for(auto it:graph[src]){
            if(v[it]==-1){
                if(dfs(it,graph,v,!c)==false) return false; 
            }
            else if(v[src]==v[it]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>v(graph.size(),-1);
        queue<int>q;
       
        for(int i=0;i<v.size();i++){
            if(v[i]==-1){
                if(dfs(i,graph,v,1)==false) return false;
        }
        }
        
        return true;
    }
};