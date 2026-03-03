class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> v(numCourses);

        // Build graph correctly: b -> a
        for(int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            v[b].push_back(a);      // correct direction
            indegree[a]++;          // indegree of a increases
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {

            int a = q.front();
            q.pop();
            ans.push_back(a);

            for(int i = 0; i < v[a].size(); i++) {

                indegree[v[a][i]]--;   // first decrease

                if(indegree[v[a][i]] == 0) {
                    q.push(v[a][i]);
                }
            }
        }

        // If cycle exists, return empty
        if(ans.size() != numCourses) return false;

        return true;
    }
};