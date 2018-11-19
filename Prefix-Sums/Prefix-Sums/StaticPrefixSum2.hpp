//
//  StaticPrefixSum2.hpp
//  Prefix-Sums
//
//  Created by Selman on 11/19/18.
//  Copyright © 2018 Selman Alpdündar. All rights reserved.
//

#ifndef StaticPrefixSum2_hpp
#define StaticPrefixSum2_hpp

#include <stdio.h>
#include <vector>

class StaticPrefixSum2 {
private:
    std::vector<bool> vector;
public:
    StaticPrefixSum2(int size, char array[]);
    int sum(int l, int r);
    
};

#endif /* StaticPrefixSum2_hpp */
