#include <iostream>

using namespace std;


int LongestBitonicSubsequence(int arr[],int n){
    
    int lisl[n];
    int lisr[n];
    
    for(int k = 0; k<n; k++){
        lisl[k] = 1;
        lisr[k] = 1;
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]> arr[j] && lisl[i] < lisl[j] +1){
                lisl[i] = lisl[j] +1;
            }
        }
    }
    
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(arr[i] > arr[j] && lisr[i] < lisr[j] +1){
                lisr[i] = lisr[j] + 1;
            }
        }
    }
    
    int max = 0;
    
    for(int i = 0; i<n; i++){
        
        int result = lisl[i] + lisr[i] - 1;
        if(max < result ){
            max = result;
        }
        
    }

    return max;
}
int main(){
    
    int t = 0;
    cin>>t;
    
    int outputs[t];
    
    for(int i = 0; i<t; i++){
        
        int n = 0;
        cin>>n;
        int inputs[n];
        
        for(int j = 0; j<n; j++){
            int number = 0;
            cin>>number;
            inputs[j] = number;
        }
        
        outputs[i] = LongestBitonicSubsequence(inputs,n);
        
        
    }
    
    for(int k = 0; k<t; k++){
        cout<<outputs[k]<<endl;
    }
    
    return 0;
}
