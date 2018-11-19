//
//  Main.cpp
//  Prefix-Sums
//
//  Created by Selman on 11/19/18.
//  Copyright © 2018 Selman Alpdündar. All rights reserved.
//

#include <iostream>
#include "StaticPrefixSum.hpp"

int main(int argc, const char * argv[]) {
    
    
    std::cout<<"-------- Static Prefix Sum Problem 1------------------"<<std::endl;
    int n = 6;
    int array[] ={5,6,123,41,55,55};
    
    StaticPrefixSum *staticPrefixSum = new StaticPrefixSum(n,array);
    std::cout<< staticPrefixSum->sum(5);
    
    std::cout<<std::endl;
    std::cout<<std::endl;
    
    return 0;
}
