void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int findRepeatNumber(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (i != nums[i] && nums[i] == nums[nums[i]])
            return nums[i];
        Swap(&nums[i], &nums[nums[i]]);
    }
    return -1;
}