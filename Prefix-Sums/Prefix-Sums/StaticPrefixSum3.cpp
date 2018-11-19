//
//  StaticPrefixSum3.cpp
//  Prefix-Sums
//
//  Created by Selman on 11/19/18.
//  Copyright © 2018 Selman Alpdündar. All rights reserved.
//

/* Problem 3
 (Number of Ways). Given an array A[1, n], count the number of ways to split
 all the elements of the array into three contiguous parts so that the sum of elements in each
 part is the same.
 More formally, you need to find the number of such pairs of indices i and j (2  i  j 
 n − 1) such that
 Pi−1
 k=1 A[k] = Pj
 k=i A[j] = Pn
 k=j+1 A[k]
 Let S be the sum of the values in the array. If 3 does not divide S, we conclude that the
 number of ways is zero. Otherwise, we compute the array C which stores in position i the
 number suffixes of A[i . . . n] that sum to S3
 . We then compute the sum of the prefixes of A.
 Every time a prefix i sums to S3
 , we add C[i + 2] to the result.
 
 
 */

#include "StaticPrefixSum3.hpp"

StaticPrefixSum3::StaticPrefixSum3(int n,int array[]){
    size = n;
    vector.reserve(n);
    
    for(int i = 0; i<n; i++){
        vector[i] = array[i];
        sum += array[i];
    }
}

int StaticPrefixSum3::split(){
    if(sum % 3 != 0){
        return -1;
    }
    
    int checkPoint = sum / 3;
    
    int temp = 0;
    
    int counter = 0;
    
    int index1, index2 = 0;
    
    for(int j=0; j<size; j++){
        temp = vector[j];
       
        if(temp == checkPoint){
           
        }
        
    }
    
    
    
    return 0;
}
