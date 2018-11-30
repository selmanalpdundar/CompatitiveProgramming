#include <iostream>
#include <vector>

int main() {


    /* Problem
         * Given an array A of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1.
         * Compute how much water can be trapped in between blocks after raining.
     */

    int t = 0;
    std::cin>>t;

    while(t != 0){ // Test cases

        std::vector<int> numbers;
        std::vector<int> rightMax;
        std::vector<int> leftMax;

        unsigned n = 0;

        std::cin>>n;

        numbers.reserve(n);
        rightMax.reserve(n);
        leftMax.reserve(n);


        for(int i = 0; i<n; i++){
           std::cin>>numbers[i];
        }


        int lMax = numbers[0];
        for(int j=1; j<n; j++){   // T(n)
            if((numbers[j-1] > numbers[j]) & (lMax < numbers[j-1])){
                leftMax[j] = numbers[j-1];
                lMax = numbers[j];
            } else {
               leftMax[j] = lMax;
            }
        }


        int rMax = numbers[n-1];

        for(int k=n-2; k>=0; k--){  // T(n)

            if((numbers[k] < numbers[k + 1]) & (rMax < numbers[k+1])){
                rightMax[k] = numbers[k+1];
                rMax = numbers[k];

            } else {
                rightMax[k] = rMax;
            }

        }


        int total = 0;

        for(int r=1; r<n-1; r++){  // T(n)

            if(rightMax[r] < leftMax[r]){
                total += rightMax[r] - numbers[r];
            } else {
                total += leftMax[r] - numbers[r];
            }
        }

        std::cout<<"Total : "<<total;  // O(n)
        t--;
    }


    return 0;
}
