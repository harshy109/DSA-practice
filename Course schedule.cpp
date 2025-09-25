class Solution {
public:
    void addEdge(int u, int v, unordered_map<int,vector<int>> &adj, vector<int> &ans){
        adj[u].push_back(v);
    }
     void topoBfs(int n,unordered_map<int,vector<int>> &adj,  vector<int> &ans){
        unordered_map<int, int> indegree;
        queue<int> q;

        //create indegree map
        for(int src = 0; src<n; src++){
            for(auto nbr : adj[src]){
                indegree[nbr]++;
            }
        }

        //maintain initial state
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        //main logic
        while(!q.empty()){
            int frontNode = q.front();
            ans.push_back(frontNode);
            q.pop();

            for(auto nbr : adj[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        reverse(ans.begin(), ans.end());

        //return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> ans;
        for(auto edge : prerequisites){
            addEdge(edge[0], edge[1], adj, ans);
        }
        
        topoBfs(numCourses,adj, ans);

        if(ans.size() == numCourses){
            return true;
        }
        else{
            return false;
        }
    }
};
