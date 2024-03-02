/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[i] * nums[i];
        printf("%d ", ans[i]);
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (ans[i] > ans[j]) {
                int t = ans[i];
                ans[i] = ans[j];
                ans[j] = t;
            }
        }
        printf("%d ", ans[i]);
    }
    return ans;
}
