#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    int size, numberOfQuery;
    cin>>size>>numberOfQuery;

    vector<int> inputs;
    vector< pair<int,int> > queries;

    inputs.reserve(size);
    queries.reserve(numberOfQuery);

    for(int i = 0; i<size; i++){
        int temp = 0;
        cin>>temp;
        inputs[i] = temp;
    }

    for(int j=0; j<numberOfQuery; j++){
        int left = 0, right = 0;
        cin>>left>>right;
        pair<int,int> temp =make_pair(left,right);
        queries[j] = temp;
    }


    






    return 0;
}