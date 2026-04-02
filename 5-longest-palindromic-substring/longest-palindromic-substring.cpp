class Solution {
public:
bool isPal(string &s){
    int low=0;
    int high=s.length()-1;
    while(low<high){
        if(s[low]!=s[high]) return false;
        low++;
        high--;
    }
    return true;
}
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.length();i++){
            string temp="";
            for(int j=i;j<s.length();j++){
                temp+=s[j];
                if(isPal(temp)&&temp.length() > ans.length())  ans = temp;;
            }
        }
    return ans;
    }

};