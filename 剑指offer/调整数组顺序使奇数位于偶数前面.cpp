/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int* exchange(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int head = 0;
    int tail = numsSize - 1;
    while (head < tail)
    {
        while (head < tail && (nums[head] & 1) == 1)
            ++head;
        while (head < tail && (nums[tail] & 1) == 0)
            --tail;
        if (head < tail)
            Swap(&nums[head], &nums[tail]);
    }

    return nums;
}