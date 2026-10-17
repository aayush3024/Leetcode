class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> index(26, -1);

        for (int i = 0; i < order.length(); i++) {
            char ch = order[i];
            index[ch - 'a'] = i;
        }

        auto myComparator = [&](char ch1, char ch2) {
            int pos1 = index[ch1 - 'a'];
            int pos2 = index[ch2 - 'a'];

            // Characters absent from order come last
            if (pos1 == -1) pos1 = 26;
            if (pos2 == -1) pos2 = 26;

            return pos1 < pos2;
        };

        sort(s.begin(), s.end(), myComparator);

        return s;
    }
};