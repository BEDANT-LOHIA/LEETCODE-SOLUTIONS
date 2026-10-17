class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int required = target-nums[i];
            if(mpp.find(required)!= mpp.end()){
                return{mpp[required],i};
            }
            else{
                mpp[nums[i]]=i;
            }
        }
        return {};
    }
};