int max(int a, int b) {
    return a > b ? a : b;
}

int maxResult(int* nums, int numsSize, int k) {
    int *dp = (int *)malloc(numsSize * sizeof(int));
    dp[0] = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int maxScore = INT_MIN;
        for (int j = i - 1; j >= i - k && j >= 0; j--) {
            maxScore = max(maxScore, dp[j] + nums[i]);
        }
        dp[i] = maxScore;
    }

    int result = dp[numsSize - 1];
    free(dp);
    return result;
    
}