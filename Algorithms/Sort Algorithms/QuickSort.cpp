#include <iostream>

int partition(int arr[],int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j= low;  j< high;  j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
     int temp = arr[high];
     arr[high] = arr[i+1];
     arr[i + 1] = temp;

    return i+1;
}


void quicksort(int arr[],int low, int high){
    if(low<high){
        int indexOfSmallestElement = partition(arr,low,high);
        quicksort(arr,low,indexOfSmallestElement-1);
        quicksort(arr,indexOfSmallestElement+1,high);
    }
}


void print(int arr[],int n){

    for(int i = 0; i<n; i++){
        std::cout<<arr[i]<<std::endl;
    }
}

int main(){
    int arr[] = {9,7,2,3,6,2,4,1,8,5};
    print(arr,10);
    quicksort(arr,0,9);
     print(arr,10);
}