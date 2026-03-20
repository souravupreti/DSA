class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>v(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>>q;
        int count=0;
         vector<int>r={1,-1,0,0};
        vector<int>c={0,0,1,-1};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(v[i][j]==0&&grid[i][j]=='1'){
                    count++;
                    q.push({i,j});
                    v[i][j]=1;
                    while(!q.empty()){
                        int a=q.front().first;
                        int b=q.front().second;
                        q.pop();

                        for(int i=0;i<4;i++){
                            int newi=a+r[i];
                            int newj=b+c[i];
                            if(newi>=0&&newj>=0&&newi<grid.size()&&newj<grid[0].size()&&v[newi][newj]!=1&&grid[newi][newj]=='1'){
                    q.push({newi,newj});
                    v[newi][newj]=1;
                }
                        }
                    }
                }
            }
        }
        return count;

    }
};