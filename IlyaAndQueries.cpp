#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    
    string array;
    
    cin>> array;
    
    int queryNumber = 0;
    
    cin>> queryNumber;
    
    cin.ignore();
    
    size_t m = array.length();
    
    if(m>pow(10,5)) return 0;
    if(queryNumber>pow(10,5)) return 0;
   
    int *sum = new int[m];
    
    for(int i = 1; i<m; i++){
        if(array.at(i) == array.at(i - 1)){
            sum[i] = sum[i - 1] + 1;
        } else {
            sum[i] = sum[i - 1];
        }
    }
    
    int *output = new int[queryNumber];
    
    
    for(int i = 0; i<queryNumber; i++)
    {
        int number1, number2 = 0;
        cin>>number1>>number2;
        
        output[i] = sum[number2-1] - sum[number1-1] ;
    }

    for(int j = 0; j<queryNumber; j++)
    {
        cout<<output[j]<<endl;
    }
    return 0;
    
}
