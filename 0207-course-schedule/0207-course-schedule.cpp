// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
//     }
// };

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1; // visiting
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 1) return true;  // cycle detected
            if (visited[neighbor] == 0 && dfs(neighbor, adj, visited)) return true;
        }
        visited[node] = 2; // visited
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (dfs(i, adj, visited)) return false;
            }
        }
        return true;
    }
};
