class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> u1;

        for(int i = 0; i < s.length(); i++){
            u1[s[i]]++;
        }

        priority_queue<pair<int,char>> pq;

        for(auto &p : u1){
            pq.push({p.second, p.first});
        }

        string ans = "";

        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            for(int i = 0; i < freq; i++){
                ans += ch;
            }
        }

        return ans;
    }
};