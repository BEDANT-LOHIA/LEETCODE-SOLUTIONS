class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxiarea = 0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int element = heights[st.top()];
                st.pop();
                int nse = i;
                int pse;
                st.empty() ? pse = -1 : pse = st.top();
                int area = element*(nse-pse-1);
                maxiarea = max(maxiarea,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int element = st.top();
            st.pop();
            int nse = n;
            int pse;
            st.empty() ? pse = -1 : pse = st.top();
            int area = heights[element]*(nse-pse-1);
            maxiarea = max(maxiarea,area);
        }
        return maxiarea;
    }
};