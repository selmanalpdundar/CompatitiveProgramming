#include <iostream>
#include <vector>

int main() {

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

        for (int k = int(array.size()-2); k>=0; k--){
            if (max < array[k]){
                max = array[k];
                leaders.push_back(max);
            }
        }

        for(int h = int(leaders.size()-1); h>= 0; h--){
            std::cout<<leaders[h]<<" ";

        }

        std::cout<<std::endl;
    }

    return 0;
}