class Solution {
public:
    bool isPowerOfThree(int n) {
        long long multiplier=1;
        while(multiplier<=n){
            if(multiplier==n)return true;
            multiplier=multiplier*3;

        }
        return false;
        
    }
};