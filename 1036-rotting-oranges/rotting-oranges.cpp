class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> v(n, vector<int>(m, 0));

        // Push all rotten oranges into queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    v[i][j] = 2;
                }
            }
        }

        int time = 0;

        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};

        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for(int i=0;i<4;i++){
                int row = r + dr[i];
                int col = c + dc[i];

                if(row>=0 && row<n && col>=0 && col<m 
                   && v[row][col]==0 
                   && grid[row][col]==1){

                    q.push({{row,col}, t+1});
                    v[row][col] = 2;
                }
            }
        }

        // Check if any fresh orange left
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && v[i][j]!=2){
                    return -1;
                }
            }
        }

        return time;
    }
};