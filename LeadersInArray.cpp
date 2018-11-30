#include <iostream>
#include <vector>

int main() {

    /* Problem
        * Given an array of positive integers.
        * Your task is to find the leaders in the array.
        * Note: An element of array is leader if it is greater than
        *  or equal to all the elements to its right side.
        * Also, the rightmost element is always a leader.
    */

    unsigned int n = 0;
    
    std::cin >> n;  // n keeps how many case will be given

    for (int i = 0; i < n; i++) {  // to take set of data for test

        unsigned int m = 0;

        std::cin >> m; // size of array

        std::vector<int> vector;
        vector.reserve(m);

        std::vector<int> leaders;

        // take give elements
        for(int j = 0; j<m; j++){
            std::cin>>vector[j];
        }

        // Take last element as a maximum 
        int max = vector[vector.size()-1];

        // Take right most element as a leader by the definition 
        leaders.push_back(vector[vector.size()-1]);

        /*  -- Algoritm --
            Take last element as a maximum and go leftforward 
            and check each element witch maximum if found a maxium 
            push it to leaders and change current maximum with it

        */
        for (int k = int(vector.size()-2); k>=0; k--){  // T(N-2)
            if (max < vector[k]){                       // T(N)
                max = vector[k];                        // T(N)
                leaders.push_back(max);                // T(N)
            }
        }
                                                      // T = 4N - 2 = O(N)
    
        for(int h = int(leaders.size()-1); h>= 0; h--){ // T(N-1)
            std::cout<<leaders[h]<<" ";                 // T(N-1)

        }
                                                        // T = 2N - 2 = O(N)
        std::cout<<std::endl;
    }

    return 0;
}
