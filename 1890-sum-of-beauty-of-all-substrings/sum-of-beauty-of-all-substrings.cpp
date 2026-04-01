class Solution {
public:
    int beautySum(string s) {
        int total = 0;

        for(int i = 0; i < s.length(); i++){
            unordered_map<char,int> u;

            for(int j = i; j < s.length(); j++){
                u[s[j]]++;

                if(u.size() <= 1) continue;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                for(auto &p : u){
                    maxi = max(maxi, p.second);
                    mini = min(mini, p.second);
                }

                total += (maxi - mini);
            }
        }

        return total;
    }
};