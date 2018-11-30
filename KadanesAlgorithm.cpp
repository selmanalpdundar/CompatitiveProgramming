#include <iostream>
#include <vector>

int main() {



    /* Problem
         * Given an array containing both negative and positive integers.
         * Find the contiguous sub-array with maximum sum.
     */
    int n = 0;
    std::cin >> n;  // n keeps how many case will be given

    for (int i = 0; i < n; i++) {  // to take set of data for test

        unsigned int m = 0;
        std::cin >> m; // size of vector
        std::vector<int> array(m);

        for(int j = 0; j<m; j++){
            std::cin>>array[j];
        }

        int sum = array[0];
        int max = array[0];

        for(int k = 1; k<m; k++){

            if(sum > 0  ){
                sum += array[k];
            } else {
                sum = array[k];
            }

            if(sum > max){
                max = sum;
            }
        }

        std::cout<<max;
        std::cout<<std::endl;
    }

    return 0;
}
