class Solution {
public:

bool issafe(int i,int j,int n,int m,
            vector<vector<char>>& board,
            vector<vector<int>> &visited,
            string &word,int idx){
    return (i>=0 && i<n && j>=0 && j<m &&
            board[i][j]==word[idx] &&
            visited[i][j]==0);
}

bool solve(vector<vector<char>>& board,string &word,
           int n,int m,vector<vector<int>> &visited,
           int i,int j,int index){

    if(index == word.length()-1){
        return true;
    }

    visited[i][j] = 1;

    // down
    if(issafe(i+1,j,n,m,board,visited,word,index+1)){
        if(solve(board,word,n,m,visited,i+1,j,index+1))
            return true;
    }

    // left
    if(issafe(i,j-1,n,m,board,visited,word,index+1)){
        if(solve(board,word,n,m,visited,i,j-1,index+1))
            return true;
    }

    // right
    if(issafe(i,j+1,n,m,board,visited,word,index+1)){
        if(solve(board,word,n,m,visited,i,j+1,index+1))
            return true;
    }

    // up
    if(issafe(i-1,j,n,m,board,visited,word,index+1)){
        if(solve(board,word,n,m,visited,i-1,j,index+1))
            return true;
    }

    visited[i][j] = 0; // backtrack

    return false;
}

bool exist(vector<vector<char>>& board, string word) {

    int n = board.size();
    int m = board[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(board[i][j] == word[0]){

                // ✅ fresh visited for each start
                vector<vector<int>> visited(n, vector<int>(m, 0));

                if(solve(board,word,n,m,visited,i,j,0)){
                    return true;
                }
            }
        }
    }

    return false;
}
};