#include <iostream>

#define middle(low,high) ((low) + (((high) - (low)) / 2))

int search(int array[], int low , int high, int element){
    
    while(low <= high){
        int middle = middle(low,high);
        
        if(array[middle] == element){
            return middle + 1;
        }
        
        if(array[middle] < element){
            low = middle + 1;
        } else {
            high = middle -1;
        }
    }
    
    return  element > array[low] ? (low+1) : low ;
}


void insertionSort(int array[],int size){
    int key,i ,j;
    
    for(i = 1; i<size; i++){
        key = array[i];
        j = i - 1;
        
        // By using binary search we decrease number of comparision  nlongn comparision
        // But swap number is still same. n^2 swap.
      int locationOfInsertion = search(array,0,j,key);
        
        while(j >= locationOfInsertion){
            array[j+1] = array[j];
            j --;
        }
        
        array[j+1] = key;
    }
    
}
void print(int arr[],int n){
    for(int i=0; i<n; i++){
        std::cout<<arr[i]<<std::endl;
    }
}

int main(){
    
    int array[] = {2,1,5,23,15,8,34};
    insertionSort(array,7);
    print(array,7);
    
    return 0;
    
}
