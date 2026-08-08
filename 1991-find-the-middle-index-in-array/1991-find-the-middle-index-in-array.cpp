class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int right_sum=0;

        int total_sum=0;
        for(int i=0;i<nums.size();i++){
            total_sum += nums[i];
        }
        int left_sum=0;
        for(int i=0;i<nums.size();i++){
            int right_sum=total_sum-left_sum-nums[i];

            if(left_sum==right_sum){
                return i;
            }
            left_sum+=nums[i];
        }
        return -1;
    }
};