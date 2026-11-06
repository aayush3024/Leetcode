class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> s;
        unordered_set<int> ans;

        for(auto x : nums1) {
            s.insert(x);
        }

        for(auto x : nums2) {
            if(s.count(x)) {
                ans.insert(x);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};