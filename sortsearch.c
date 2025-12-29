#include <stdio.h>

void bubbleSort(int arr[], int size)
{
    int swapped, temp;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void binarySearch(int arr[], int size, int key)
{
    bubbleSort(arr, size);

    int left = 0, right = size - 1, mid, found = 0;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            found = 1;
            break;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (found)
        printf("%d is found at index %d after sorting.\n", key, mid);
    else
        printf("%d is not found in the array.\n", key);
}

int main()
{
    int num, key, ch;

    printf("Enter total number of elements: ");
    scanf("%d", &num);

    if (num <= 0)
    {
        printf("Invalid number of elements.\n");
        return 0;
    }

    int arr[num];

    printf("Enter elements:\n");
    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    do
    {
        printf("\nEnter Choice:\n1) Binary Search\n2) Bubble Sort\n3) Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter number to find: ");
            scanf("%d", &key);
            binarySearch(arr, num, key);
            break;

        case 2:
            bubbleSort(arr, num);
            printf("Sorted Array: { ");
            for (int i = 0; i < num; i++)
                printf("%d ", arr[i]);
            printf("}\n");
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (ch != 3);

    return 0;
}
