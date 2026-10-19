class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int start =0;
        int cnt =0;
        for(int i=0;i<n;i++){
            if(nums[i]<target){
                start++;
            }
            if(nums[i]== target){
                cnt++;
            }
        }
        vector<int>ans;
        for(int i=start;i<start+cnt;i++){
            ans.push_back(i);
        }
        return ans;
    }
};