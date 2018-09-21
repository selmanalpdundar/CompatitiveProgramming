//
//  main.cpp
//  Next Larger Element
//
//  Created by Selman on 9/21/18.
//  Copyright © 2018 Selman Alpdündar. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

const int NUMBER_OF_ELEMENT = 10;
const int CONSTANT = 10;

// To see array
void printArr(int *arr){
    for(int i = 0 ; i<NUMBER_OF_ELEMENT; i++){
        cout<< arr[i]<<" ";
    }
}

//

// Trivial
void findNextBigElement(int *arr){
    
    for(int i=0; i<NUMBER_OF_ELEMENT; i++){
        bool isFounded = false;
        
        for(int j=i; j<NUMBER_OF_ELEMENT; j++){
            if(arr[i]<arr[j]){
                isFounded = true;
                cout<<arr[j]<<" ";
                break;
            }
        }
        
        if(!isFounded){
            cout<<-1<<" ";
        }
    }
}

void findNextBigElement2(){
    
}

int main(int argc, const char * argv[]) {
    
    // Creating Array
    int arr[NUMBER_OF_ELEMENT];
   
    srand (time(NULL));

    for(int i=0; i<NUMBER_OF_ELEMENT; i++){
        arr[i] = rand() % NUMBER_OF_ELEMENT * CONSTANT + 1;
    }
    
    
    cout<<"The orginal array"<<endl;
    printArr(arr);
    cout<<endl<<endl;
    
    cout<<"Next Larger Number - Trivial"<<endl;
    findNextBigElement(arr);
    cout<<endl<<endl;
    
    
    return 0;
}
