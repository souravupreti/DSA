class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int spaces=0;
        int spacet=0;
        int i=s.size()-1;
        int j=t.size()-1;
        while(i>=0||j>=0){
            //s
            while(i>=0){
                if(s[i]=='#'){
                    spaces++;
                    i--;
                }else if(spaces>0){
                    i--;
                    spaces--;
                }
                else{
                    break;
                }
            }
            while(j>=0){
                if(t[j]=='#'){
                    spacet++;
                    j--;
                }else if(spacet>0){
                    j--;
                    spacet--;
                }
                else{
                    break;
                }
            }
            if((i>=0)!=(j>=0))
            return false;

            if(i >= 0 && j >= 0&&s[i]!=t[j])
            return false;

            
            i--;
            j--;
        }
        return true;

    }
};