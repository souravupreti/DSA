class Solution {
public:
    bool check(int src,vector<int> &v,vector<vector<int>>& graph){
        queue<int>q;
        q.push(src);
        v[src]=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0;i<graph[temp].size();i++){
                if(v[graph[temp][i]]==-1){
                    q.push(graph[temp][i]);
                    v[graph[temp][i]]=!v[temp];
                }
                else if(v[temp]==v[graph[temp][i]]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>v(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
                if(v[i]==-1){
                if(check(i,v,graph)==false) return false;
            
            }
            
        }
        return true;
    }
};