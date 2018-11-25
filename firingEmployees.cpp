#include <iostream>
#include <vector>

int main() {


    int t = 0;

    std::vector< std::vector<int> > vectors;

    std::cin>>t;

    for(int i = 0; i<t; i++){

        int n = 0;

        std::cin>>n;

        std::vector<int> vector;


        for(int j=0; j<n; j++){
            int temp = 0;
            std::cin>>temp;
            vector.push_back(temp);
        }
        vectors.push_back(vector);

    }

    return 0;
}