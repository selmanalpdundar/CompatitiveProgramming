#include <iostream>
#include <vector>

#define RANGE 9

void countingSort(std::vector<int>, int n){
    
    int count[RANGE+1] = {0};
    int output[n];

    // Count All Element
    for(int i = 0; i<n; i++){
        count[arr[i]] += 1;
    }

    // Sum all element with previoues element
    for(int j = 1; j<=RANGE; j++){
        count[j] += count[j-1];
    }

    // Put value of element to value of count and decrease it
    for(int k = 0;  k<n; k++){
        output[count[arr[k]]-1] = arr[k];
        count[arr[k]] -=1;
    }

    // Copy the output to original array
    for(int t = 0; t<n; t++){
        arr[t] = output[t];
    }
    
}

int main(){

    int t = 0;
    std::cin>> t;
    std::cout<<std::endl;
    std::vector<std::string> vector;
    vector.reserve(t);

    while(t>0){
        std::string number;
        std::cin>> number;
        vector.push_back(number);
        t--;
    }

    for(int i = 0; i<vector.size(); i++){

        // To prevent loging first digit 0 I take all numbers as a string
        // And convert string to integer array
        std::vector<int> digits = stringToIntegerArray(vector[i]);
        
        // Sorting nlogn
        std::sort(digits.begin(), digits.end());

        int smallestEven = 0;
        bool flag = false;

        /*
        If digit is equals 0 or even
        I break the loop because array is sorted next
        even will be bigger or equal to this
        */

        for(int j = 0; j < digits.size(); j++){
            if( digits[j] == 0 || digits[j] % 2 == 0){
                smallestEven = digits[j];
                flag = true;
                break;
            }
        }

        /* I start to print from back of the digits and 
            check if current element is smallestEvent digit
        */
        for(int k = digits.size() -1; k>=0; k--){
            if(digits[k] != smallestEven){
                std::cout<<digits[k];
            }
        }

       // I check is thre even or not and print it
       if(flag == true){
           std::cout<<smallestEven;
       }


       std::cout<<std::endl;
    }
  

}