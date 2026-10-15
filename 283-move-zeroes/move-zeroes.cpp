class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros=-1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeros = i;
                break;
            }
        }
        if(zeros == -1)
            return;
        for(int i=zeros+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[zeros]);
                zeros++;
            }
        }
    }
};