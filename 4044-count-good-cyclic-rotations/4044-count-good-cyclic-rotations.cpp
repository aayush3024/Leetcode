class Solution {
public:
    int countGoodRotations(vector<int>& nums) {

        int n = nums.size();
        int m = n / 2;
        int count = 0;

        long long firstsum = 0;
        long long secondsum = 0;

        for(int i = 0; i < m; i++) {
            firstsum += nums[i];
        }

        for(int i = m; i < n; i++) {
            secondsum += nums[i];
        }

        // Check original array
        if(firstsum > secondsum) {
            count++;
        }

        // Sliding window
        for(int i = 0; i < n-1; i++) {

            firstsum -= nums[i];
            secondsum += nums[i];

            firstsum += nums[(i + m) % n];
            secondsum -= nums[(i + m) % n];

            if(firstsum > secondsum) {
                count++;
            }
        }

        return count;
    }
};