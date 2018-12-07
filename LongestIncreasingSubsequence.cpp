#include <iostream>



int lis(int arr[], int n){
   
    int lis[n];

    for(int k = 0; k<n; k++){
        lis[k] = 1;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]> arr[j] && lis[i] < lis[j] +1){
                lis[i] = lis[j] +1;
            }
        }
    }

    int max = lis[0];

    for(int t=0; t<n; t++){
        if(lis[t] > max){
            max = lis[t];
        }
    }
    return max;

}

int main(){

    int arr[] = {10,22,9,33,21,50,41,60};
    int n = 8;
    std::cout<<lis(arr,n)<<std::endl;
    return 0;
}