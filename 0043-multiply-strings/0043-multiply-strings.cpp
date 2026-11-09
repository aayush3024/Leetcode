class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n = num1.size();
        int m = num2.size();

        vector<int> ans(n + m, 0);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int mul = a * b;

                int sum = mul + ans[i + j];

                ans[i + j] = sum % 10;
                ans[i + j + 1] += sum / 10;
            }
        }

        string result = "";

        for (int digit : ans) {
            result += to_string(digit);
        }

        while (result.size() > 1 && result.back() == '0') {
            result.pop_back();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};