#include <iostream>
#include <vector>
#include <deque>


int main() {

    /* Problem
         * Given an array A and an integer K.
         * Find the maximum for each and every contiguous subarray of size K.
     */

    /* Study Resources
     *  1.
     */

    int t = 0; // number of test case

    std::cin>>t;

    while(t!= 0 ){

        unsigned int n =0;
        unsigned int k =0;

        std::cin>>n;
        std::cin>>k;

        std::vector<int> numbers;
        std::deque<int> deque;
        std::vector<int> result;


        numbers.reserve(n);


        for(int i =0; i<n; i++){
            std::cin>>numbers[i];
        }


        for(int i =0; i<n; i++){

            if(!deque.empty() && deque.front() == i - k) {
                deque.pop_front();
            }

            while (!deque.empty() && numbers[deque.back()] < numbers[i]){
                deque.pop_back();
            }

            deque.push_back(i);

            if(i >= k-1){
                result.push_back(numbers[deque.front()]);
            }

        }


        for(int j=0; j<result.size(); j++){

            std::cout<<result[j]<<" ";
        }


        std::cout<<std::endl;


        t--;
    }


    return 0;
}