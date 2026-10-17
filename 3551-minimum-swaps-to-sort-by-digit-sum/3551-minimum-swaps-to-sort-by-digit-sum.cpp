class Solution {
public:
    int digitsum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> aftersorted = nums;

        auto lambda = [&](int num1, int num2) {
            int sum1 = digitsum(num1);
            int sum2 = digitsum(num2);

            if (sum1 != sum2) {
                return sum1 < sum2;
            }

            return num1 < num2;
        };

        sort(aftersorted.begin(), aftersorted.end(), lambda);

        unordered_map<int, int> valToIdx;

        for (int i = 0; i < n; i++) {
            valToIdx[nums[i]] = i;
        }

        int swapcount = 0;

        for (int i = 0; i < n; i++) {
            int expectedval = aftersorted[i];
            int currval = nums[i];

            if (expectedval == currval) {
                continue;
            }

            int idx = valToIdx[expectedval];

            swap(nums[i], nums[idx]);

            valToIdx[currval] = idx;
            valToIdx[expectedval] = i;

            swapcount++;
        }

        return swapcount;
    }
};