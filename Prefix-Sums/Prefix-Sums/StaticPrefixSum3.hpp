//
//  StaticPrefixSum3.hpp
//  Prefix-Sums
//
//  Created by Selman on 11/19/18.
//  Copyright © 2018 Selman Alpdündar. All rights reserved.
//

#ifndef StaticPrefixSum3_hpp
#define StaticPrefixSum3_hpp

#include <stdio.h>
#include <vector>

class StaticPrefixSum3{
  
    
private:
    int sum;
    int size;
    std::vector<int> vector;
    
public:
    StaticPrefixSum3(int n, int array[]);
    int split();
    
};



#endif /* StaticPrefixSum3_hpp */
