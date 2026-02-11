class Solution {
public:

int row[4]={1,-1,0,0};
  int col[4]={0,0,1,-1};
  bool valid(int i,int j,int n,int m){
      return i>=0 && i<n && j>=0 && j<m;
  }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    grid[i][j]=0;
                }
            }
        }

        int ans=0;
        while(!q.empty()){
            int time=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            ans=max(ans,time);
            q.pop();
            
            for(int k=0; k<4; k++){
                int newx=r+row[k];
                int newy=c+col[k];
                if(valid(newx,newy,n,m) && grid[newx][newy]==1){
                    q.push({time+1,{newx,newy}});
                    grid[newx][newy]=0;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;



        
    }
};