class Solution {
public:
    int LargestRectangleArea(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        int width;
        int maxarea = 0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int height = st.top();
                st.pop();
                if(st.empty()) 
                    width = i;
                else 
                    width = i-st.top() -1;
                maxarea = max(maxarea,heights[height]*width);
            }
            st.push(i);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m,0);
        int maxarea = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            maxarea = max(maxarea,LargestRectangleArea(heights));
        }
        return maxarea;
    }
};