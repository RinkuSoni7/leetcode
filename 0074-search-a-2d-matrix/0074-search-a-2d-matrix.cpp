class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int e=row*col-1,s=0;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(matrix[mid/col][mid%col]==target){
                return 1;
            }else if(matrix[mid/col][mid%col]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }

        }
        return 0;
        
    }
};