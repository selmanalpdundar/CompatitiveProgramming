//
//  StaticPrefixSum2.cpp
//  Prefix-Sums
//
//  Created by Selman on 11/19/18.
//  Copyright © 2018 Selman Alpdündar. All rights reserved.
//

/*
 Problem 2: (Ilya and Queries). Given a string s = s1s2 . . . sn consisting only of characters
 a and b and m queries. Each query is described by a pair of integers l, r ( ≤ l < r ≤ n). The
 answer to the query l, r is the number of such integers i ∈ [l, r] that si = si+1.
 
 Solution:
 The idea is that of computing the binary vector B[1, n−1] such that B[i] = 1 if si = si+1,
 0 otherwise. This way, the answer to the query l, r equals Pr
 i=l B[i]. Thus, the problem is
 solved efficiently (constant time per query) by computing prefix-sums on vector B.
 */
#include "StaticPrefixSum2.hpp"
void sum( char array[], int n, int, bool binary_vector[]){
    for(int i =0; i<n-1; i++){
        if(binary_vector[i] == binary_vector[i+1]){
            binary_vector[i] = 1;
        } else {
            binary_vector[i] = 0;
        }
    }
}
