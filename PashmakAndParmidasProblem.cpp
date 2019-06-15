#include <iostream>
#include <vector>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);

    int n = 0;

    cin>>n;

    vector<int> inputs;
    inputs.reserve(n);

    for(int i=0; i<n; i++){
        int number = 0;
        cin>>number;
        inputs.push_back(number);
    }
    return 0;
}