//
//  StaticPrefixSum.hpp
//  Prefix-Sums
//
//  Created by Selman on 11/19/18.
//  Copyright © 2018 Selman Alpdündar. All rights reserved.
//

#ifndef StaticPrefixSum_hpp
#define StaticPrefixSum_hpp

#include <iostream>
#include <vector>

class StaticPrefixSum {
private:
    std::vector<int> prefix_sum;
    
public:
    StaticPrefixSum(int size, int array[]);
    int sum(int l);
};
#endif /* StaticPrefixSum_hpp */
