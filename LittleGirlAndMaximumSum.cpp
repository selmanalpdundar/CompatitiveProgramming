#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int size, numberOfQuery;
    cin>>size>>numberOfQuery;

    vector<int> inputs;
    vector<int> queries;

    inputs.reserve(size);
    queries.reserve(numberOfQuery+1);

    for(int i = 0; i<size; i++){
        int temp = 0;
        cin>>temp;
        inputs[i] = temp;
    }

    for(int j=0; j<numberOfQuery; j++){
        int left = 0, right = 0;
        cin>>left>>right;
        queries[left]+=1;
        
        if(right<size){
            queries[right+1] -=1;
        }
        
    }

    for (int i = 1; i <=size; i++) {
            queries[i]+= queries[i-1];
    }


    std::sort(inputs.begin(),inputs.end());
    std::sort(queries.begin(),queries.end());

    long long su = 0;

    for (int i = 0; i < size; i++) {
         su+=inputs[i]*queries[i+1];
    }

    cout<<su;






    return 0;
}