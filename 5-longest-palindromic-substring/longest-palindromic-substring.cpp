class Solution {
public:
    bool isPal(string &s, int low, int high){
        while(low < high){
            if(s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                
                if(isPal(s, i, j) && (j - i + 1) > ans.length()){
                    ans = s.substr(i, j - i + 1);  
                }
            }
        }

        return ans;
    }
};