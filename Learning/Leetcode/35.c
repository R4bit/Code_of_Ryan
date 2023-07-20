/*
35. 搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
*/

int searchInsert(int* nums, int numsSize, int target)
{
    int j = 0;
    for (int i = 0; i < numsSize; i++ , j++)
    {
        if (target <= nums[i])
        {
            int* new_nums = (int*)malloc( sizeof(int) * (numsSize + 1));
            if (new_nums == NULL)
            {
                return -1;
            }
            nums = new_nums;
            for (int k = numsSize - 1; k >= i; k--)
            {
                nums[k + 1] = nums[k];
            }
            nums[i] = target;
            j = i;
            numsSize++;
            break;
        }
        
    }
    return j;
}