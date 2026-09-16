class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;

        int currentMax = 0;
        int maxSum = nums[0];

        int currentMin = 0;
        int minSum = nums[0];

        for (int x : nums) {

            // Kadane for maximum subarray
            currentMax = max(x, currentMax + x);
            maxSum = max(maxSum, currentMax);

            // Kadane for minimum subarray
            currentMin = min(x, currentMin + x);
            minSum = min(minSum, currentMin);

            totalSum += x;
        }

        // All elements are negative
        if (maxSum < 0)
            return maxSum;

        // Non-circular vs circular
        return max(maxSum, totalSum - minSum);
    }
};