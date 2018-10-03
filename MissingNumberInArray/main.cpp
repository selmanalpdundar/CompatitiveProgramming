#include <iostream>
#include <vector>

int main() {

    int n = 0;
    std::cin >> n;  // n keeps how many case will be given

    for (int i = 0; i < n; i++) {  // to take set of data for test

        unsigned int m = 0;
        std::cin >> m; // size of vector
        std::vector<int> array(m-1);

        for(int j = 0; j<m-1; j++){
            std::cin>>array[j];
        }


        int sum = (m*(m+1))/2;      // Gauss summation formula

        for(int k = 0; k<m-1; k++){
            sum -= array[k];
        }

        std::cout<<sum;
        std::cout<<std::endl;
    }

    return 0;
}