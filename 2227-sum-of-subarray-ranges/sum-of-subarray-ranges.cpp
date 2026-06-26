class Solution {
public:
    vector <int> PreviousSmallerElement(vector<int>& nums){
        stack<int>st;
        vector<int> pse(nums.size());
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
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
    vector <int> NextSmallerElement(vector<int>& nums){
        stack<int> st;
        vector<int> nse(nums.size());
        for(int i= nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(st.empty())
                nse[i] = nums.size();
            else
                nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector <int> PreviousGreaterElement(vector<int>& nums){
        stack<int> st;
        vector<int> pge(nums.size());
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();
            st.push(i);
        }
        return pge;
    }
    vector <int> NextGreaterElement(vector<int>& nums){
        stack<int> st;
        vector<int> nge(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(st.empty())
                nge[i] = nums.size();
            else
                nge[i] = st.top();
            st.push(i);
        }
        return nge;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int> pse = PreviousSmallerElement(nums);
        vector<int> nse = NextSmallerElement(nums);
        vector<int> pge = PreviousGreaterElement(nums);
        vector<int> nge = NextGreaterElement(nums);
        long long Minisums = 0;
        long long Maxisums = 0;
        for(int i=0;i<nums.size();i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            Minisums += 1LL*right*left*nums[i];
        }
        for(int i=0;i<nums.size();i++){
            int left = i - pge[i];
            int right = nge[i] - i;
            Maxisums += 1LL*right*left*nums[i];
        }
        long long total = Maxisums - Minisums;
        return total;
    }
};