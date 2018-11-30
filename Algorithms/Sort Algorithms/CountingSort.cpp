#include <iostream>
#define RANGE 9

void countingSort(int arr[], int n){
    
    int count[RANGE+1] = {0};
    int output[n];

    // Count All Element
    for(int i = 0; i<n; i++){
        count[arr[i]] += 1;
    }

    // Sum all element with previoues element
    for(int j = 1; j<=RANGE; j++){
        count[j] += count[j-1];
    }

    // Put value of element to value of count and decrease it
    for(int k = 0;  k<n; k++){
        output[count[arr[k]]-1] = arr[k];
        count[arr[k]] -=1;
    }

    // Copy the output to original array
    for(int t = 0; t<n; t++){
        arr[t] = output[t];
    }
    
}

void print(int arr[],int n){
    for(int i=0; i<n; i++){
        std::cout<<arr[i]<<std::endl;
    }
}

int main(){

    int array[] = {1,5,6,2,3,4,7,2,7,8,9};
    int n  = 11;
    
    print(array,n);
    countingSort(array,n);
    print(array,n);

}