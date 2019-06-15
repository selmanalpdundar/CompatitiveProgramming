#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream> // for streaming string to tokens

using namespace std;

void inc(){

}

int rmq(){

    return 1;
}

int main(){
    std::ios_base::sync_with_stdio(false);

    int n = 0;
    cin>>n;
    
    vector<int> inputs;
    inputs.reserve(n);

    for(int i =0; i<n; i++){
        int item = 0 ;
        cin>> item;
        inputs.push_back(item);
    }

    int numberOfOperation = 0;
    cin>> numberOfOperation;
    vector<int> outputs;

    for(int j = 0; j<numberOfOperation; j++){
        
        string input;
        getline(cin,input);
        int count = std::count(input.begin(),input.end(),' ');

        if(count == 2){
            
            outputs.push_back(rmq()); //

        } else {

            inc(); //
        }
        
    }

    return 0;
}