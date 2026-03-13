class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        for(int i=0;i<num.length();i++){
            while(!s.empty()&&s.top()-'0'>num[i]-'0'&&k>0){
                s.pop();
                k=k-1;
            }
            s.push(num[i]);
        }
        string ans="";
        while(k>0) {
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        while(ans.length()!=0&&ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans.empty()) return "0";
        return ans;

    }
};