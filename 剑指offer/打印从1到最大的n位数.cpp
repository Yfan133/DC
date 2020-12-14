/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printNumbers(int n, int* returnSize)
{
    *returnSize = pow(10, n) - 1;
    int* arr = (int*)malloc(4 * (*returnSize));
    for (int i = 1; i <= *returnSize; i++)
        arr[i - 1] = i;
    return arr;
}