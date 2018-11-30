#include <iostream> 
#include <vector> // Dynamic Array
#include <deque>  // Double Ended Queue

int main() {

    /* Problem
         * Given an array A and an integer K.
         * Find the maximum for each and every contiguous subarray of size K.
     */

    int t = 0; // number of test case

    std::cin>>t;  

    while(t!= 0 ){

        // ------ Declaration of Variables ----------- //

        unsigned int n = 0;  // it is not going to be lower than 0
        unsigned int k = 0;  // it is not going to be lower than 0

        std::cin>>n; // Array Size
        std::cin>>k; // Windows size

        std::vector<int> numbers; // Stores given array
        std::deque<int> deque;    // Stores windows element 
        std::vector<int> result;  // Stores maximums in windows


        /* To prevent descreasing of performance we reserve
           element size therefore the vector will not copy and 
           extend it size on runtime.
        */
        numbers.reserve(n);


        // Reading Number and Pusing to Vector
        for(int i =0; i<n; i++){
            std::cin>>numbers[i];
        }


        for(int i =0; i<n; i++){

            // Remove element that is not inside range of windows      
            if(!deque.empty() && deque.front() == i - k) {
                deque.pop_front();
            }

            // Remove element that smaller than current element.
            while (!deque.empty() && numbers[deque.back()] < numbers[i]){
                deque.pop_back();
            }

            // Push back current element.
            deque.push_back(i);

            // Check if i grater or equal to k - 1  push front to result array.
            if(i >= k-1){
                result.push_back(numbers[deque.front()]);
            }

        }


        // Printing result to out.
        for(int j=0; j<result.size(); j++){

            std::cout<<result[j]<<" ";
        }
        std::cout<<std::endl;

        // decreasing test count
        t--;
    }


    return 0;
}