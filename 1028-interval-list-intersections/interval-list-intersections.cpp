class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0;
        int j=0;
        vector<vector<int>> ans;

        while(i<firstList.size()&&j<secondList.size()){
            int start1=firstList[i][0];
            int end1=firstList[i][1];

            int start2=secondList[j][0];
            int end2=secondList[j][1];

            if(start1<=start2){
                if(end1>=start2){
                    int start3=max(start1,start2);
                    int end3=min(end1,end2);
                    ans.push_back({start3,end3});
                }
                }
                 else{
                    if(end2>=start1){
                    int start3=max(start1,start2);
                    int end3=min(end1,end2);
                    ans.push_back({start3,end3});
                }
               
            }
             if(end1>=end2){
                    j++;
                }
            else{
                    i++;
                }

        }
        return ans;

    }
};