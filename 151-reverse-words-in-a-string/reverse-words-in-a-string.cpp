class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0;
        int j=s.length()-1;
        while(s[i]==' '){
           i++;
            }
      while(s[j]==' '){
            j--;
        }
        string temp="";
        for(int k=j;k>=i;k--){
            if(k!=j&&s[k+1]==' '&&s[k]==' ')continue;
            if(s[k]==' '){
                ans+=temp+' ';
                temp="";
                continue;
            }
            temp=s[k]+temp;
        }
        return ans+temp;
    }
};