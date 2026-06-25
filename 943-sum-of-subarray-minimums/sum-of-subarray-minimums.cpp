class Solution {
public:
    vector<int>  nextsmallerelement(vector<int>& arr){
        stack<int> st;
        vector<int> nse(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = arr.size();
            else
                nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> previoussmallerelement(vector<int>& arr){
        stack<int> st;
        vector<int> pse(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
                if(st.empty())
                    pse[i] = -1;
                else
                    pse[i] = st.top();
                st.push(i);
            }
            return pse;
        }
    
    int sumSubarrayMins(vector<int>& arr) {
        int modi = 1e9 + 7;
        int n =  arr.size();
        vector <int> nse = nextsmallerelement(arr);
        vector <int> pse = previoussmallerelement(arr);
        int total = 0;
        for(int i=0;i<n;i++){
             int left = i-pse[i];
             int right = nse[i] - i;
             total = (total + (left*right*1LL*arr[i])%modi)%modi;
        }
        return total;  
    }
};