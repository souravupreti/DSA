class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> u1;
        u1['I']=1;
        u1['V']=5;
        u1['X']=10;
        u1['L']=50;
        u1['C']=100;
        u1['D']=500;
        u1['M']=1000;

        int sum = 0;

        for(int i = 0; i < s.length(); i++){
            if(i < s.length() - 1 && u1[s[i]] < u1[s[i+1]]){
                sum -= u1[s[i]];  
            } else {
                sum += u1[s[i]];   
            }
        }

        return sum;
    }
};