class Solution {
public:
    bool isPowerOfFour(int n) {
        long long multiplier=1;
        while(multiplier<=n){

            if(multiplier==n)return true;
            multiplier=multiplier*4;
        }
        return false;
    }
};