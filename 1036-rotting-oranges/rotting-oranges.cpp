class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>v(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    v[i][j]=1;
                }
            }
        }
        int time=0;
        vector<int>r={1,-1,0,0};
        vector<int>c={0,0,1,-1};
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time,t);
            for(int k=0;k<4;k++){
                int newi=i+r[k];
                int newj=j+c[k];
                if(newi>=0&&newj>=0&&newi<n&&newj<m&&v[newi][newj]!=1&&grid[newi][newj]==1){
                    q.push({{newi,newj},t+1});
                    v[newi][newj]=1;
                }
            }
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==0&&grid[i][j]==1) return -1;
            }
        }
        return time;

    }
};