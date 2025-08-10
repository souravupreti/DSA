class Solution {
public:
    int roeFind(vector<vector<int>>& mat,int mid){
        int ans=INT_MIN;
        int index=-1;
        for(int i=0;i<mat.size();i++){
            if(ans<mat[i][mid]){
                index=i;
                ans=mat[i][mid];
            }
        }
        return index;

    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int start=0;
        int end=m-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int row=roeFind(mat,mid);
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<m?mat[row][mid+1]:-1;
            if(mat[row][mid]>left&&mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return {-1,-1};
    }
};