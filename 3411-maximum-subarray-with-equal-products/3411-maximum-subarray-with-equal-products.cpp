class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n =nums.size();
        int res=0;
        for(int i=0;i<n;i++){

        int prod_val=nums[i];
        int lcm_val=nums[i];
        int gcd_val=nums[i];

        for(int j=i+1;j<n;j++){

            prod_val=prod_val*nums[j];
            gcd_val=gcd(gcd_val,nums[j]);
            lcm_val=lcm(lcm_val,nums[j]);

            if(prod_val>gcd_val*lcm_val){
                break;
            }if(prod_val==gcd_val*lcm_val){
                res=max(res,j-i+1);
               }
               
            }

        }
        return res;


        
    }
};