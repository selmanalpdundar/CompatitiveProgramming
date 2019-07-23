#include <iostream>

using namespace std;

void swap(int arr[],int left,int right);
void quicksort(int arr[],int left, int right);
void quicksort(int arr[], int size);
int partition(int arr[],int left, int right, int pivot);
void print(int arr[],int size);


int main(){
    int arr[] = {9,7,2,3,6,2,4,1,8,5};
   
    int size = sizeof(arr) / sizeof(typeof(arr[0]));
    print(arr,size);
    quicksort(arr, size);
    print(arr,size);
}


int partition(int arr[],int left, int right, int pivot){
    
    while(left<=right){
        
        while(arr[left] < pivot){ left++; }
        
        while(arr[right] > pivot){ right--; }
        
        if(left <= right){
            swap(arr, left, right);
            left++;
            right--;
        }
    }
    
    return left;
}

void quicksort(int arr[],int size){
    quicksort(arr,0,size-1);
}

void quicksort(int arr[],int left, int right){
    
    if(left >= right) return;
    
    int pivot = arr[(left + right) / 2];
    int indexOfSmallestElement = partition(arr,left,right,pivot);
    quicksort(arr,left,indexOfSmallestElement-1);
    quicksort(arr,indexOfSmallestElement+1,right);

}

void print(int arr[],int size){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap(int arr[],int left,int right){
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}
