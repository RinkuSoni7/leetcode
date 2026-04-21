class Solution {
public:
int ans;
vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

void solve(vector<vector<int>>& grid,int n,int m,int x,int y,int count,int nonobstacle){


    if(x<0 || x>=n ||y<0 || y>=m|| grid[x][y]==-1) return;

    if(grid[x][y]==2){
        if(count==nonobstacle)
        ans++;

        return;
    }

    
// int temp=grid[x][y];
    grid[x][y]=-1;

    for(vector<int>& dir : directions){
        int newx=x+dir[0];
        int newy=y+dir[1];

        solve(grid,n,m,newx,newy,count+1,nonobstacle);

    }
grid[x][y]=0;


}
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        ans=0;

        int nonobstacle=0;
        int count=0;
         int start_x = 0, start_y = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0)
                    nonobstacle++;    
        

            if(grid[i][j]==1){
                 start_x=i;
                 start_y=j;
            }
        }
        }
        nonobstacle+=1;

        solve(grid,n,m,start_x,start_y,count,nonobstacle);

return ans;


    }
};