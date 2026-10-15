class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int remember = 0;
        int cnt =1;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[remember]){
               nums[remember+1] = nums[i];
               cnt++;
            remember++;
            }
        }
        return cnt;
    }
};