class Solution {
public:

void find(int row,int n,vector<vector<string>>&ans,vector<string>&Board,vector<bool>&coloumn,vector<int>&leftdig,vector<int>&rightdig){

    if(row==n){
        ans.push_back(Board);
        return;
    }

    for(int j=0; j<n; j++){

    if(coloumn[j]==0 && leftdig[n-1+j-row]==0 && rightdig[row+j]==0){
        coloumn[j]=1;
        Board[row][j]='Q';
        leftdig[n-1+j-row]=1;
        rightdig[row+j]=1;
        find(row+1,n, ans, Board, coloumn,leftdig,rightdig);
        coloumn[j]=0;
        Board[row][j]='.';
        leftdig[n-1+j-row]=0;
        rightdig[row+j]=0;



    }
    }
}



       
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>Board(n);
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        Board[i].push_back('.');
        vector<int>leftdig(2*n-1);
        vector<int>rightdig(2*n-1);
        vector<bool>coloumn(n,0);

        find(0,n,ans,Board,coloumn,leftdig,rightdig);
        return ans;

    
        
    }
};