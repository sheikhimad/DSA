#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;  
        else if (arr[mid] < key)
            low = mid + 1;   
        else
            high = mid - 1;  
    }

    return -1; 
}

int main() {
    int n,i, key, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in sorted order: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);

    if (result == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at position %d (index %d).\n", result + 1, result);

    return 0;
}

