class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& v,
             vector<vector<char>>& g, int parent1, int parent2) {

        v[i][j] = 1;
        char ch = g[i][j];

        vector<int> r = {1, -1, 0, 0};
        vector<int> c = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++) {
            int newi = i + r[k];
            int newj = j + c[k];

            if(newi >= 0 && newj >= 0 &&
               newi < g.size() && newj < g[0].size() &&
               g[newi][newj] == ch) {

                if(v[newi][newj] == 0) {
                    if(dfs(newi, newj, v, g, i, j)) return true;
                }
                else if(!(newi == parent1 && newj == parent2)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> v(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] == 0) {
                    if(dfs(i, j, v, grid, -1, -1)) return true;
                }
            }
        }
        return false;
    }
};