#include <iostream>


// N^2
int lds(int arr[], int n){
   
    int lds[n];
    for(int k = 0; k<n; k++){
        lds[k] = 1;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]< arr[j] && lds[i] < lds[j] +1){
                lds[i] = lds[j] +1;
            }
        }
    }

    int max = lds[0];

    for(int t=0; t<n; t++){
        if(lds[t] > max){
            max = lds[t];
        }
    }
    return max;

}

int main(){

    int arr[] = {100,5,3,89,31,20,50};
    int n = 7;
    std::cout<<lds(arr,n)<<std::endl;
    return 0;
}