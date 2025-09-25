class Solution {
  public:
    bool cycleDetectionUndirectedBFS(  int src, unordered_map<int, bool>& visited,  vector<vector<int>> adj){
        //bfs ka code - undirected
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto nbr : adj[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    parent[nbr] = frontNode;
                    visited[nbr] = true;
                }
                else if(visited[nbr]==true && nbr != parent[frontNode] ){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfsDetect(int src, unordered_map<int, bool>& visited, vector<vector<int>>& adj, int parent){
        visited[src] = true;
        for(auto nbr : adj[src]){
            if(!visited[nbr]){
                bool ans = dfsDetect(nbr, visited, adj, src);
                if(ans){
                    return true;
                }
                else if(visited[nbr] && nbr != parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& adj) {
        // bool ans = false;
        // int n = V;
        // unordered_map<int, bool> visited;
        // for(int i = 0; i<=n; i++){
        //     if(!visited[i]){
        //         ans = cycleDetectionUndirectedBFS(i, visited, adj);
        //         if(ans){
        //             break;
        //         }
        //     }
        // }
        // return ans;
        
        int parent = -1;
        bool ans = false;
        unordered_map<int, bool> visited;
        for(int i = 1;i<=V; i++){
            if(!visited[i]){
                ans = dfsDetect(i, visited, adj, parent);
                if(ans == true){
                    break;
                }
            }
        }
        return ans;
    }
};
