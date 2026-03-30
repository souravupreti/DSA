class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp="";
        int minLength=INT_MAX;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<minLength){
                temp=strs[i];
                minLength=strs[i].length();
            }
        }

        string ans="";
        for(int i=0;i<minLength;i++){
            int count=0;
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=temp[i]) return ans;
                else count++;
            }
            if(count==strs.size()){
                ans+=temp[i];
            }
        }
        return ans;
    }
};