//
//  Main.cpp
//  Prefix-Sums
//
//  Created by Selman on 11/19/18.
//  Copyright © 2018 Selman Alpdündar. All rights reserved.
//

#include <iostream>
#include "StaticPrefixSum.hpp"
#include "StaticPrefixSum2.hpp"

int main(int argc, const char * argv[]) {
    
    
    std::cout<<"-------- Static Prefix Sum Problem 1------------------"<<std::endl;
    int n = 6;
    int array[] ={5,6,123,41,55,55};
    
    StaticPrefixSum *sps1 = new StaticPrefixSum(n,array);
    std::cout<< sps1->sum(5);
    
    std::cout<<std::endl;
    std::cout<<std::endl;
    
    
    std::cout<<"-------- Static Prefix Sum Problem 2------------------"<<std::endl;

    int m = 10;
    char arr[] = {'a','b','b','b','a','a','b','a','a','a'};
    
    StaticPrefixSum2 *sps2 = new StaticPrefixSum2(m,arr);
    
    std::cout<<sps2->sum(0,5);
    
    
    std::cout<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"-------- Static Prefix Sum Problem 3------------------"<<std::endl;
    
    
    
    std::cout<<std::endl;
    std::cout<<std::endl;
    return 0;
}
