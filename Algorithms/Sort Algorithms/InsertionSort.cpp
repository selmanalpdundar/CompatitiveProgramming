#include <iostream>

void insertionSort(int array[],int size){
    int key,i ,j;

    for(i = 1; i<size; i++){
        key = array[i];
        j = i - 1;

        while(j>= 0 && array[j]> key){
            array[j+1] = array[j];
            j -= 1;
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