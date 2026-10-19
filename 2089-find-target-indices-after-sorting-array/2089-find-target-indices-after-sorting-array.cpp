class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                ans.push_back(i);
            }
        }
       return ans; 
    }
};