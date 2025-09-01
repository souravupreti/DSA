class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty()&&k>0&& (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k=k-1;
            }
            st.push(num[i]);
        }
        while(k>0) {
            st.pop();
            k=k-1;
        }
        if(st.empty()){
            return "0";
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }
        res = res.substr(i);

        return res.empty() ? "0" : res;

    }
};