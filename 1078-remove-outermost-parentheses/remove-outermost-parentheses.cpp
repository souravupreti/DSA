class Solution {
public:
    string removeOuterParentheses(string s) {

        int counta=0;
        int countb=0;
        int last=-1;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') counta++;
            else countb++;

            if(counta-countb==0){
                for(int j=last+2;j<i;j++){
                    ans+=s[j];
                }

                last=i;
            }
        }
        return ans;
    }
};