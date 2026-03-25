class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total=0;
        // if(grid.size()<=1) return true;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                total+=grid[i][j];
            }
        }
        if(total%2!=0) return false;
        long long target=total/2;
        long long sum=0;
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                sum+=grid[i][j];
            }
            if(sum==target) return true;
        }
        sum=0;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                sum+=grid[j][i];
            }
            if(sum==target) return true;
        }
        return false;


    }
};