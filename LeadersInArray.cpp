#include <iostream>
#include <vector>

int main() {


    /* Problem
        * Given an array of positive integers. Your task is to find the leaders in the array.
        * Note: An element of array is leader if it is greater than or equal to all the elements to its right side.
        * Also, the rightmost element is always a leader.
    */

    unsigned int n = 0;

    std::cin >> n;  // n keeps how many case will be given

    for (int i = 0; i < n; i++) {  // to take set of data for test

        unsigned int m = 0;
        std::cin >> m; // size of array

        std::vector<int> array(m);
        std::vector<int> leaders;

        for(int j = 0; j<m; j++){
            std::cin>>array[j];
        }


        int max = array[array.size()-1];

        // Rightmost element always leader.
        leaders.push_back(array[array.size()-1]);

        for (int k = int(array.size()-2); k>=0; k--){  // T(N-2)
            if (max < array[k]){                       // T(N)
                max = array[k];                        // T(N)
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
