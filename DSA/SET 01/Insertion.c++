#include <stdio.h>

void insertionSort(int n , int arr[]){
    int i, key, j;

    for(i = 1; i<n; i++){
        key = arr[i];
        j = i-1;

        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;        
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {1,6,7,9,23,2,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    insertionSort(size, arr);

    printArray(arr, size);

    return 0;
}