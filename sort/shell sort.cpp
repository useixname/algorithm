#include <stdio.h>

// 基本希尔排序算法
void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 不同增量序列的希尔排序实现
void shellSortWithSequence(int arr[], int n, int sequence[], int seqLength)
{
    for (int k = 0; k < seqLength; k++)
    {
        int gap = sequence[k];
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 打印数组元素
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr1[] = {12, 34, 54, 2, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("原始数组1: ");
    printArray(arr1, n1);

    // 调用基本希尔排序
    shellSort(arr1, n1);

    printf("希尔排序后的数组1: ");
    printArray(arr1, n1);

    // 使用不同增量序列的希尔排序
    int arr2[] = {64, 25, 12, 22, 11};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\n原始数组2: ");
    printArray(arr2, n2);

    // 使用不同增量序列 {5, 3, 1} 进行希尔排序
    int sequence[] = {5, 3, 1};
    int seqLength = sizeof(sequence) / sizeof(sequence[0]);

    shellSortWithSequence(arr2, n2, sequence, seqLength);

    printf("希尔排序后的数组2: ");
    printArray(arr2, n2);

    return 0;
}
