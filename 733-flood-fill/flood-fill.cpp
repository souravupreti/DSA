class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> n = image;
        int startColor = image[sr][sc];
        if(startColor == color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        n[sr][sc]=color;
        int ra[4] = {0,0,1,-1};
        int ca[4] = {-1,1,0,0};
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int r=i+ra[k];
                int c=j+ca[k];
                if(r>=0 && c>=0 && r<image.size() && c<image[0].size() && n[r][c]==startColor){
                    n[r][c]=color;
                    q.push({r,c});
                }
            }
        }
        return n;
    }
};