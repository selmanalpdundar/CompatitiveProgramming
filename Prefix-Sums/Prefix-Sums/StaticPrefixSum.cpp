//
//  StaticPrefixSum.cpp
//  Prefix-Sums
//
//  Created by Selman on 11/19/18.
//  Copyright © 2018 Selman Alpdündar. All rights reserved.
//

/*
 Problem 1 :  (Range sum). Given an array A[1, n] of integers, we would like to support the
 query Sum(i), which returns the sum of the elements in A[1, . . . , i].
 
 Solution:
 The array doesn’t change so the problem is trivial. Simply precompute the answers to all
 the possible (only n) queries. The operation Sum can be used to answer RangeSum queries.
 Given two indexes i and j, RangeSum(i, j) returns the sum of the elements in A[i . . . j]. The
 latter query is very useful to solve other problems. The next one is an easy example.
 
 */


#include "StaticPrefixSum.hpp"
#include <iostream>

StaticPrefixSum::StaticPrefixSum(int size, int array[]){
    prefix_sum.reserve(size);
    prefix_sum.push_back(array[0]);
    
    for(int i=1; i<size; i++){
        prefix_sum.push_back(prefix_sum[i-1] + array[i]);
    }
}

int StaticPrefixSum::sum(int i){
    return prefix_sum[i - 1];
}
