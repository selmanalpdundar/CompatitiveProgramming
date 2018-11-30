#include <iostream>
#include <vector>

int main() {

    /* Problem
         * Given an array C of size N-1 and given that
         * there are numbers from 1 to N with one element missing,
         * the missing number is to be found.
     */
    int n = 0;
    std::cin >> n;  // n keeps how many case will be given

    for (int i = 0; i < n; i++) {  // to take set of data for test

        unsigned int m = 0;
        std::cin >> m; // size of vector
        std::vector<int> array(m-1);

        for(int j = 0; j<m-1; j++){
            std::cin>>array[j];
        }

        /* ----- Algorithm -------
            1.Calculate the sum of numbers froms 1 to N
            2.Subtract each element from sum 
            3.Print Sum
        */
        
        int sum = (m*(m+1))/2;      // Gauss summation formula

        for(int k = 0; k<m-1; k++){
            sum -= array[k];
        }

        std::cout<<sum;
        std::cout<<std::endl;
    }

    return 0;
}
