#include <iostream>
#include <vector>
#include <string>

std::vector<int> stingToIntegerArray(std::string integer){



    char array[integer.size()];

    std::strcpy(array,integer.c_str());

     std::vector<int> vector;

    vector.reserve(integer.size());

    for(int i = 0; i<integer.size(); i++){

        vector.push_back((int)array[i] - 48);
    }


    return vector;
}

int main(){

    int t = 0;

    std::cin>> t;
    std::cout<< std::endl;

    std::vector<std::string> vector;

    vector.reserve(t);


    while(t>0){
        std::string number;
        std::cin>> number;
        vector.push_back(number);
        t--;
    }

    for(int i = 0; i<vector.size(); i++){

        std::vector<int> digits = stingToIntegerArray(vector[i]);
        std::sort(digits.begin(), digits.end());


        int smallestEven = 0;
        bool flag = false;

        for(int j = 0; j < digits.size(); j++){

            if( digits[j] == 0 || digits[j] % 2 == 0){
                smallestEven = digits[j];
                flag = true;
                break;
            }
        }

        for(int k = digits.size() -1; k>=0; k--){
            if(digits[k] != smallestEven){
                std::cout<<digits[k];
            }
        }


       if(flag == true){
           std::cout<<smallestEven;
       }


       std::cout<<std::endl;
    }

    return 0;
}