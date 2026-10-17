class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int left=0;
        int bottom = n-1;
        vector<int> row;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            row.clear();
            for(int j=bottom;j>=0;j--){
                row.push_back(matrix[j][i]);
            }
            ans.push_back(row);
        }
        matrix = ans;
    }
};