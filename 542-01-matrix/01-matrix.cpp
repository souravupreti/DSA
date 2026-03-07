class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        queue<pair<pair<int,int>,int>> q;

        int r[4] = {0,0,1,-1};
        int c[4] = {1,-1,0,0};

        vector<vector<int>> ans = mat;
         vector<vector<int>>v(ans.size(),vector<int>(ans[0].size(),0));
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++){
                if(ans[i][j]==0){
                    q.push({{i,j},0});
                    v[i][j]=1;
                }
            }
        }

        while(!q.empty()){

            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){

                int rw = i + r[k];
                int cw = j + c[k];

                if(rw>=0 && cw>=0 && rw<ans.size() && cw<ans[0].size() && ans[rw][cw]==1 && v[rw][cw]==0){

                    ans[rw][cw] = t + 1;
                    v[rw][cw]=1;
                    q.push({{rw,cw}, t+1});
                }
            }
        }

        return ans;
    }
};