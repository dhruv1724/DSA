class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>ans(matrix.size(),0);
        for(int i=0;i<matrix.size();i++){
            int degree=0;
            for(int j=0;j<matrix[0].size();j++){
                degree+=matrix[i][j];
            }
            ans[i]=degree;
        }
        return ans;
    }
};