class Solution {
public:
    long long minMoves(vector<int>& nums) {

        int n = nums.size();

        int maxi = nums[0];

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            if(nums[i] > maxi) {
                maxi = nums[i];
            }

            sum = sum + nums[i];
        }

        long long ans = (long long)n * maxi - sum;

        return ans;
    }
};