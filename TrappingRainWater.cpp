#include <iostream>
#include <vector>

int main() {
    /* Problem
         * Given an array A of N non-negative integers representing 
         * height of blocks at index i as Ai where the width of each block is 1.
         * Compute how much water can be trapped in between blocks after raining.
     */

    int t = 0;
    std::cin>>t;

    while(t != 0){ // Test cases

        std::vector<int> numbers; // Stores given array
        std::vector<int> rightMax; // Stores right maximum of current element
        std::vector<int> leftMax;  // Stores reft maximum of current element

        unsigned n = 0;

        std::cin>>n;

        numbers.reserve(n);
        rightMax.reserve(n);
        leftMax.reserve(n);


        for(int i = 0; i<n; i++){
           std::cin>>numbers[i];
        }

        // Take first element as a left maximum
        int lMax = numbers[0];
        
        /* Algorithm
           1. Iterate from left to right
           2. Check current block  with previous block
           3. Check current previous block with left maximum
           4. if current block is smaller than previous and
              previous block is bigger than left maximum 
              change left maximum with previous block value
              and assagin it left maximum of current element
        
         */ 
        for(int j=1; j<n; j++){   // T(n)
            if((numbers[j-1] > numbers[j]) & (lMax < numbers[j-1])){
                leftMax[j] = numbers[j-1];
                lMax = numbers[j];
            } else {
               leftMax[j] = lMax;
            }
        }

         /* Algorithm
           1. Iterate from right to left
           2. Check current block  with posterior block
           3. Check current posterior block with  right maximum
           4. if current block is smaller than previous and
              previous block is bigger than right maximum 
              change right maximum with posterior block value
              and assagin it right maximum of current element
        
         */ 
        int rMax = numbers[n-1];
        for(int k=n-2; k>=0; k--){  // T(n)
            if((numbers[k] < numbers[k + 1]) & (rMax < numbers[k+1])){
                rightMax[k] = numbers[k+1];
                rMax = numbers[k];

            } else {
                rightMax[k] = rMax;
            }
        }

        /*   Algorithm to calculate trapped water 
             we have left and right maximum block size of each element 
             so we can calculate with just subtraction of them

            1. Check wich side is bigger
            2. If right is smaller 
                Subract right with current element value
                and add it to total
            3. If left is smaller
                subtract left with current element value 
                and add it to total
        */

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
