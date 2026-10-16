class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0;
        int neg=1;
        vector<int> ans;
        ans = nums;
        for(int i=0;i<nums.size();i++){
            if(ans[i]>0){
                nums[pos] = ans[i];
                pos += 2;
            }
            else{
                nums[neg] = ans[i];
                neg += 2;
            }
        }
        return nums;
    }
};