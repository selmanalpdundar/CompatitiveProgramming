#include <iostream>


void merge(int arr[], int low, int middle, int high){
    
    int rightCounter, leftCounter, generalCounter;
    
    int sizeOfLeftArray =  middle - low + 1;
    int sizeOfRightArray = high - middle;

    int Left[sizeOfLeftArray];
    int Right[sizeOfRightArray];

    for(leftCounter = 0; leftCounter<sizeOfLeftArray; leftCounter++){
        Left[leftCounter] =  arr[low + leftCounter];
    }

    for(rightCounter = 0; rightCounter<sizeOfRightArray; rightCounter++){
        Right[rightCounter] = arr[middle + rightCounter +1];
    }

    rightCounter = 0;
    leftCounter = 0;
    generalCounter = low;

    while(rightCounter < sizeOfRightArray && leftCounter < sizeOfLeftArray){
        if(Left[leftCounter]<= Right[rightCounter]){
            arr[generalCounter] = Left[leftCounter];
            leftCounter++;
        } else {
            arr[generalCounter] = Right[rightCounter];
            rightCounter++;
        }
        generalCounter++;
    }

    while(leftCounter< sizeOfLeftArray){
        arr[generalCounter] = Left[leftCounter];
        leftCounter++;
        generalCounter++;
    }

    while(rightCounter< sizeOfRightArray){
        arr[generalCounter] = Right[rightCounter];
        rightCounter++;
        generalCounter++;
    }

}

void mergesort(int arr[],int low, int high){
    if(low<high){
        int middle = low + (high - low )/2;
        mergesort(arr,low,middle);
        mergesort(arr,middle+1,high);
        merge(arr,low,middle,high);
    }
    
}

void print(int arr[],int n){

    for(int i = 0; i<n; i++){
        std::cout<<arr[i]<<std::endl;
    }
}

int main(){

    int arr[] = {9,3,6,2,4,1};
    mergesort(arr,0,5);
    print(arr,6);
}