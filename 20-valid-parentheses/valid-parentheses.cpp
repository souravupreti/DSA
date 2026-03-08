class Solution {
public:
    bool isValid(string st) {
        stack<char>s;
        for(int i=0;i<st.length();i++){
            int c=st[i];
            if(c=='('||c=='{'||c=='['){
                s.push(c);
            }
            else{
                if(s.empty()) return false;
                else{
                    if(c==')'&&s.top()=='('||c=='}'&&s.top()=='{'||c==']'&&s.top()=='['){
                        s.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return s.empty()?true:false;
    }
};