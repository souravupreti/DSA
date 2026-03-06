class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<pair<int,int>,int>> q;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        int time = 0;

        int r[4] = {0,0,1,-1};
        int c[4] = {-1,1,0,0};

        while(!q.empty()){

            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;

            q.pop();

            time = max(time,t);

            for(int k=0;k<4;k++){

                int rn = i + r[k];
                int cw = j + c[k];

                if(rn>=0 && cw>=0 && rn<n && cw<m && grid[rn][cw]==1){

                    grid[rn][cw] = 2;

                    q.push({{rn,cw},t+1});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return time;
    }
};