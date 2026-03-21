class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>v(graph.size(),-1);
        queue<int>q;
       
        for(int i=0;i<v.size();i++){
            if(v[i]==-1){
                 q.push(i);
                 v[i]=1;
                while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto it:graph[a]){
                if(v[it]==-1){
                    v[it]=!v[a];
                    q.push(it);
                }
                else if(v[a]==v[it]){
                    return false;
                }
            }
        }
            }
        }
        
        return true;
    }
};