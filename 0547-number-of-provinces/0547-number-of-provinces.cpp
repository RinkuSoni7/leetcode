class Solution {
public:
int n;
void dfs(vector<vector<int>>&isConnected,int src,vector<int>&visited){
    visited[src]=1;
    for(int v=0; v<n; v++){
        if(!visited[v] && isConnected[src][v]==1){
            dfs(isConnected,v,visited);
        }
        
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
         n=isConnected.size();
        // vector<vector<int>>adj(n);

        vector<int>visited(n,0);

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(isConnected[i][j]==1){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }


        int count=0; 
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(isConnected,i,visited);
                count++;
            }
        }

        return count;
    }
};