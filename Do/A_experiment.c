#include <stdio.h>

int main() {
    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int **p;   // 定义一个指向指针的指针变量
    int i, j;

    // 将二级指针指向二维数组的第一个元素的地址
    p = (int **)arr;

    // 使用二级指针来遍历二维数组
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", *((int *)p + i * 3 + j));
        }
        printf("\n");
    }

    return 0;
}

for (int i = 0; i < n; i++) 
{
    char ch = pairs(s[i]);
    if (ch) 
    {
        if (top == 0 || steak[top - 1] != ch) {
            return false;
        }
        top--;
    } else {
        steak[top++] = s[i];
    }
}
