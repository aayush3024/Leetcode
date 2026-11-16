class Solution {
public:
    string digitSum(string s, int k)
    {
        while(s.size() > k)
        {
            string ns;

            for(int i = 0; i < s.size(); i++)
            {
                int curr = 0;

                for(int j = i; j < i+k && j < s.size(); j++)
                    curr += (s[j] - '0');

                i = i+k-1;

                ns += to_string(curr);
            }

            s = ns;
        }

        return s;
    }
};