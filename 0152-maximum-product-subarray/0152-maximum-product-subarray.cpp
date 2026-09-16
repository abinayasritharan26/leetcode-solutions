class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProduct = nums[0];
        int minProduct = nums[0];
        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int x = nums[i];

            int newMax = max({
                x,
                x * maxProduct,
                x * minProduct
            });

            int newMin = min({
                x,
                x * maxProduct,
                x * minProduct
            });

            maxProduct = newMax;
            minProduct = newMin;

            answer = max(answer, maxProduct);
        }

        return answer;
    }
};