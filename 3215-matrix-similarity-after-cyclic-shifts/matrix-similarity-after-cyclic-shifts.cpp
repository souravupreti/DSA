class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>m=mat;
        for(int i=0;i<k;i++){
            for(int j=0;j<mat.size();j++){
                if(j%2==0){
                    int a=m[j][0];
                    for(int p=1;p<mat[j].size();p++){
                        m[j][p-1]=m[j][p];
                }
                m[j][m[j].size()-1]=a;
                }
                else{
                    int b=m[j][m[j].size()-1];
                    for(int q=m[j].size()-2;q>=0;q--){
                        m[j][q+1]=m[j][q];
                    }
                    m[j][0]=b;
                }
                
            }
        }

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]!=m[i][j]) return false;
            }
        }
        return true;
    }
};