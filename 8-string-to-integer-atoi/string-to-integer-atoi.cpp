class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int i;
        int n=s.length();
        for(i=0;i<s.length();i++){
            if(s[i]!=' ') break;
        }
        int sign=1;
        if(i < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1;
            i++;
        }
        for(int k=i;k<s.length();k++){
            if(s[k]!=0) break;
            i++;
        }
        
        for(int f=i;f<n;f++){
            if(s[f] == '+' || s[f] == '-') break;
            else if(s[f]>='a'&&s[f]<='z') break;
            else if(s[f]==' ') break;
            else if(s[f]=='.') break;
            else ans=ans*10+s[f]-'0';
             if(sign == 1 && ans > INT_MAX) return INT_MAX;
    if(sign == -1 && -ans < INT_MIN) return INT_MIN;
            
        }
        return ans*sign;

    }
};