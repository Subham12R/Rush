#include <stdio.h>

int binarySearch(int arr[], int key, int n) {
    int low = 0, high = n - 1;
    int mid = low + (low - high)/2;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}

int main(){
    int arr[] = {1,6,7,9,23,2,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int key = 9;
    int result = binarySearch(arr, key, size);

    if(result == -1) printf("Element not found\n");
    else printf("Element found at index %d\n", result);

    return 0;


}