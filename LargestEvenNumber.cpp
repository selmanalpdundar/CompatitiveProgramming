#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;


#define RANGE 9

void countingSort(vector<int> &arr, int n){
    
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

vector<int> stringToIntegerArray(string integer){
    
    char array[integer.size()];
    strcpy(array,integer.c_str());
    vector<int> vector;
    vector.reserve(integer.size());
    
    for(int i = 0; i<integer.size(); i++){
        vector.push_back((int)array[i] - 48);
    }
    
    return vector;
}

int main(){
    
    int t = 0;
    cin>> t;
    vector<string> array;
    array.reserve(t);
    
    while(t>0){
        string number;
        cin>> number;
        array.push_back(number);
        t--;
    }
    
    for(int i = 0; i<array.size(); i++){
        vector<int> digits = stringToIntegerArray(array[i]);
        int size = digits.size() - 1;
     
        countingSort(digits,size+1);
        
        int smallestEven = 0;
        bool flag = false;
        int countOfSmallest = 0 ;
        

        
        for(int j = size; j>=0; j--)
        {
            if(digits[j] % 2 == 0)
            {
                if(smallestEven == digits[j]){
                    countOfSmallest += 1;
                }else{
                  smallestEven = digits[j];
                  countOfSmallest = 1;
                }
                flag = true;
            }
        }
        

        for(int k = size; k>=0; k--)
        {
            if(digits.at(k) == smallestEven)
            {
                if(countOfSmallest > 1)
                {
                    cout<<digits.at(k);
                    countOfSmallest--;
                }
            }
            else
            {
               cout<<digits.at(k);
            }
        }
        
        if(flag == true){
            cout<<smallestEven;
        }
        
        cout<<endl;
    }
    
    return 0;
}
