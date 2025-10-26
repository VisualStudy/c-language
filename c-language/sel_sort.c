#include <stdio.h>

void SelSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[min_index])
            {
                min_index = j;
            }
        }

            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
    }
}

int main(void)
{
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    SelSort(arr, n);

    printf("선택 정렬 결과: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}